# Linked List and Graph in C

This project is a simple implementation of a linked list and a graph in C. The linked list is used to store the snake's body in the snake game, and the

## 🚀 Getting Started

Follow the instructions below to have the project running locally.

## ❤️ Contribution

Contributions are welcome! To contribute, favorite the project and give your opinion about it!

## 🐬 Improve the Project.

Help improve the project! Fork it and develop your creativity!

>https://github.com/KauaHenSilva/c_grap_list_enc


## 📋 Prerequisites (Installation Docker) (Linux)

The project was developed in the Ubuntu environment, so the commands may vary according to the operating system. The project uses the following dependencies: 

### Docker
  
  ```bash
  sudo apt-get -y install docker
  ```

## 📦 Installation with Docker (Linux)

1. **Clone this repository:**

  ```bash
  git clone https://github.com/KauaHenSilva/c_app_list_enc
  ```

2. **Navigate to the project directory:**

  ```bash
  cd c_app_list_enc
  ```
3. **Build:**

  ```bash
  sudo docker build -t c_app_list_enc .
  ```

4. **Run:**

  ```bash
  sudo docker run -it --rm --env DISPLAY=$DISPLAY --env XAUTHORITY=$XAUTHORITY --volume /tmp/.X11-unix:/tmp/.X11-unix c_app_list_enc
  ```

## 📋 Prerequisites (Installation Local) (Linux)

The project was developed in the Ubuntu environment, so the commands may vary according to the operating system. The project uses the following dependencies: 

### GCC 

  ```bash
  sudo apt install build-essential
  ```

### Meson 

  ```bash
  sudo apt-get -y install meson 
  ```

### Ninja 

  ```bash
  sudo apt-get -y install ninja-build
  ```

### GTK 

  ```bash
  sudo apt-get -y install libgtk-3-dev
  ```

## 📦 Local Installation  (Linux)
To install the project locally, follow the steps below:

1. **Clone this repository:**

  ```bash
  git clone https://github.com/KauaHenSilva/c_app_list_enc
  ```
2. **Navigate to the project directory:**

  ```bash
  cd c_app_list_enc
  ```
3. **setup:**

  ```bash
  meson setup builddir
  ```
4. **build:**

  ```bash
  ninja -C builddir
  ```

5. **run:**

  ```bash
  ./builddir/src/main
  ```
