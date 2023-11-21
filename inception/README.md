# Preliminary questions

Docker and Docker Compose are tools that help manage and deploy applications.

Docker is a platform that uses containerization to manage multiple images and containers. It provides a way to package an application with all of its dependencies into a standardized unit for software development. Docker images are lightweight, standalone, executable packages that include everything needed to run a piece of software, including the code, a runtime, libraries, environment variables, and config files.

Docker Compose, on the other hand, is a tool for defining and running multi-container Docker applications. It uses a YAML file to configure the application's services, and with a single command, you can create and start all the services from your configuration. Docker Compose is particularly useful for defining your application stack in a file, keeping it at the root of your project repository, and easily enabling someone else to contribute to your project.

The difference between a Docker image used with Docker Compose and without Docker Compose lies in how the image is deployed and managed. When you use Docker Compose, you can define multiple services that make up your application in a single file, and Docker Compose takes care of starting and linking those services together. When you use Docker without Docker Compose, you manage each container individually, and you need to manually set up any links between containers.

The benefits of Docker compared to Virtual Machines (VMs) are numerous:

+ Efficiency: Docker containers are lightweight and share the host system’s kernel, making them much more efficient than VMs, which require a full OS per VM.

+ Speed: Docker containers can start much faster than VMs because they don't need to boot an entire operating system.

+ Consistency: Docker containers run the same, regardless of the environment they're running in. This eliminates the "it works on my machine" problem.

+ Isolation: Each container runs in isolation from others, similar to how VMs isolate applications and their dependencies from each other. However, unlike VMs, Docker containers share the host system’s OS kernel, which makes them more lightweight and efficient.

+ Portability: Docker containers can be easily moved between different systems, making them highly portable.

# Docker network

Docker networking is a system that manages communications between containers, your Docker host, and the outside world. It is required for Docker containers to connect with each other and the outside world through the host system. Docker supports many network types, each suited to certain use cases staragile.com.

Docker's networking subsystem is pluggable, using drivers. Several drivers exist by default, and provide core networking functionality docs.docker.com.

+ Bridge: This is the default network driver. If you don't specify a driver, this is the type of network you are creating. Bridge networks are commonly used when your application runs in a container that needs to communicate with other containers on the same host.

+ Host: This driver removes network isolation between the container and the Docker host, and uses the host's networking directly.

+ Overlay: Overlay networks connect multiple Docker daemons together and enable Swarm services and containers to communicate across nodes. This strategy removes the need to do OS-level routing.

+ IPvlan: IPvlan networks give users total control over both IPv4 and IPv6 addressing. The VLAN driver builds on top of that in giving operators complete control of layer 2 VLAN tagging and even IPvlan L3 routing for users interested in underlay network integration.

+ Macvlan: Macvlan networks allow you to assign a MAC address to a container, making it appear as a physical device on your network. The Docker daemon routes traffic to containers by their MAC addresses. Using the macvlan driver is sometimes the best choice when dealing with legacy applications that expect to be directly connected to the physical network, rather than routed through the Docker host's network stack.

+ None: This driver completely isolates a container from the host and other containers.

# Launch shell in container

To launch a shell in a container run `docker exec -it <container_id_or_name> /bin/bash`.

# MariaDB

To get a MySQL command prompt run `docker exec -it <container_id_or_name> mysql -u <username> -p`
where `<container_id_or_name>` can be obtained using `docker ps`.

`show schemas;` to show the available databases.
`use <database>;` to pick a database.
`show tables;` to print the different tables in the database.
`describe <table_name>;` to inspect the values in a specific table.
