# At the time of writing, the latest stable version of Debian is Debian 12
# Bookworm, therefore since the subject asks us to use the penultimate
# version of Debian, we use Debian 11 Bullseye.
FROM debian:bullseye

# Set debconf's to non-interactive mode to reduce output and required
# interaction. We need to use ARG and not ENV so that this variable does
# not persists after build.
ARG DEBIAN_FRONTEND=noninteractive

# Update the system, install new packages and clean the cache
RUN apt-get update -y && apt-get -y upgrade && apt-get install -y nginx openssl dumb-init && apt-get clean && rm -rf /var/lib/apt/lists/*

# Generate SSL Key and certificate
RUN openssl req -x509 -newkey rsa:2048 -nodes -subj "/C=FR/ST=Rhône/L=Charbonnières-les-Bains/O=42/CN=www.mbarberi.42.fr " -keyout /etc/ssl/mbarberi.42.fr.key -out /etc/ssl/mbarberi.42.fr.crt
#   req                 - Used for generating certificate signing requests (CSRs) and self-signed certificates
#   -x509               - We want a self-signed certificate rather than a CSR
#   -newkey rsa:2048    - Generate a RSA key pair with a key length of 2048 bits
#   -nodes              - We do not want to encrypt the the private key with a passphrase -> no decryption needed
#   - subj /C=FR        - Subject of the certificate -> country code FR (used to identify the identity that the certificate belongs to)
#   - keyout <path>     - Path and filename for the private key
#   - out <path>        - Path and filename for the self-signed certificate

# NGINX configuration file
COPY /conf/nginx.conf /etc/nginx/sites-available/mbarberi.42.fr.conf
RUN ln -s /etc/nginx/sites-available/mbarberi.42.fr.conf /etc/nginx/sites-enabled/mbarberi.42.fr.conf

# Port 443
EXPOSE 443

# CMD command will be passed as argument to ENTRYPOINT
# dumb-init acts as PID 1 and immediately spawns your command as a child
# process, taking care to properly handle and forward signals as they are
# received.
ENTRYPOINT ["/usr/bin/dumb-init", "--"]

# -g flag -> set global directive or variables
# daemon off directive -> NGINX stay in the foreground
CMD ["nginx", "-g", "daemon off;"]
