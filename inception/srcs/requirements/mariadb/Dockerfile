# At the time of writing, the latest stable version of Debian is Debian 12
# Bookworm, therefore since the subject asks us to use the penultimate
# version of Debian, we use Debian 11 Bullseye.
FROM debian:bullseye

# Define build-time variables that can be passed to Docker during the build
# process. The actual values are specified in the Dockerfile under the
# 'args' subsection.
ARG DB_USER
ARG DB_DATABASE
ARG DB_USER_PASSWORD
ARG DB_ROOT_PASSWORD

# Set debconf's to non-interactive mode to reduce output and required
# interaction. We need to use ARG and not ENV so that this variable does
# not persists after build.
ARG DEBIAN_FRONTEND=noninteractive

# Update the system, install new packages and clean the cache
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y mariadb-server dumb-init && apt-get clean && rm -rf /var/lib/apt/lists/*

# Give permission to mysql group
RUN mkdir -p /var/run/mysql /var/log/mysql/ && chown -R mysql:mysql /var/run/mysql /var/log/mysql/

# Start mysql and create database
# ALTER USER: change authentification characteristics of a databse user
# GRANT: Grant user permissions to all tables in the database from localhost
# FLUSH PRIVILEGES: changes take effect immediatly
RUN service mariadb start && mariadb -u root -e "CREATE DATABASE IF NOT EXISTS $DB_DATABASE; \
	ALTER USER 'root'@'localhost' IDENTIFIED BY '$DB_ROOT_PASSWORD'; \
	GRANT ALL PRIVILEGES ON $DB_DATABASE.* TO '$DB_USER'@'%' IDENTIFIED BY '$DB_USER_PASSWORD'; \
	FLUSH PRIVILEGES;"

COPY ./conf/mariadb.conf ./etc/mysql/mariadb.conf.d/50-server.cnf

# The EXPOSE instruction informs Docker that the container listens on the
# specified network ports at runtime. The EXPOSE instruction does not
# actually publish the port.
EXPOSE  3306

# CMD command will be passed as argument to ENTRYPOINT
# dumb-init acts as PID 1 and immediately spawns your command as a child
# process, taking care to properly handle and forward signals as they are
# received.
ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["mysqld", "--bind-address=0.0.0.0"]
