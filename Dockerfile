# Exemple Linux

# sudo docker build -t c_app_list_enc .
# sudo docker run -it --rm --env DISPLAY=$DISPLAY --env XAUTHORITY=$XAUTHORITY --volume /tmp/.X11-unix:/tmp/.X11-unix c_app_list_enc

FROM ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies

RUN apt-get update && apt-get install -y
RUN apt-get install -y meson
RUN apt-get install -y libgtk-3-dev
RUN apt-get install -y ninja-build

# Copy the source code
COPY . /app

# Set the working directory
WORKDIR /app

# Build the application
RUN meson builddir
RUN ninja -C builddir

# Run the application
CMD ["./builddir/main"]