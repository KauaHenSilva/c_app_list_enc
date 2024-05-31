# Exemple Linux

# sudo docker build -t c_app_list_enc .
# sudo docker run -it --rm --env DISPLAY=$DISPLAY --env XAUTHORITY=$XAUTHORITY --volume /tmp/.X11-unix:/tmp/.X11-unix c_app_list_enc

FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies

RUN apt-get update && apt-get install -y
RUN apt-get -y install meson=0.56.2-0ubuntu1
RUN apt-get -y install libgtk-3-dev=3.24.24-4ubuntu1
RUN apt-get -y install ninja-build=1.10.0-1

# Copy the source code
COPY . /app

# Set the working directory
WORKDIR /app

# Build the application
RUN meson builddir
RUN ninja -C builddir

# Run the application
CMD ["./builddir/main"]
