FROM ubuntu:22.04

RUN apt update;\
    apt install --yes software-properties-common; \
    apt update
RUN DEBIAN_FRONTEND=noninteractive apt install --yes \
        autoconf \
        automake \
        bison \
        build-essential \
        ccache \
        clang-15 \
        cmake \
        ninja-build \
        doxygen \
        gdb \
        git \
        graphviz

ARG USERNAME=app
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -m $USERNAME \
    && apt-get update \
    && apt-get install --yes sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME

USER $USERNAME
