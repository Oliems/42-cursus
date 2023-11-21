# At the time of writing, the latest stable version of Debian is Debian 12
# Bookworm, therefore since the subject asks us to use the penultimate
# version of Debian, we use Debian 11 Bullseye.
FROM debian:bullseye

# Set debconf's to non-interactive mode to reduce output and required
# interaction. We need to use ARG and not ENV so that this variable does
# not persists after build.
ARG DEBIAN_FRONTEND=noninteractive

# Update the system, install new packages and clean the cache
RUN apt-get update -y && apt-get upgrade -y && apt-get install -y curl php php-fpm php-mysql php-mysqli mariadb-client dumb-init && apt-get clean && rm -rf /var/lib/apt/lists/*

# Download WP-CLI and set execution permission
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
	&&		chmod +x wp-cli.phar \
	&&		mv wp-cli.phar /usr/local/bin/wp

# Create wordpress installation directory
RUN mkdir -p /var/www/html/wordpress

# Copy install script to /tmp
COPY /tools/launch_wordpress.sh /tmp

# Copy configuration file
COPY /conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

# The EXPOSE instruction informs Docker that the container listens on the
# specified network ports at runtime. The EXPOSE instruction does not
# actually publish the port.
EXPOSE 9000

# CMD command will be passed as argument to ENTRYPOINT
# dumb-init acts as PID 1 and immediately spawns your command as a child
# process, taking care to properly handle and forward signals as they are
# received.
ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["sh", "/tmp/launch_wordpress.sh"]
