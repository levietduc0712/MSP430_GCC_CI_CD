# MSP430FR6989 Microcontroller CI/CD Debugging Setup

This repository utilizes Docker to containerize the MSP430 toolchain for development and CI/CD workflows. The Docker image includes the necessary tools for compiling and debugging MSP430 firmware. This setup is specifically for the MSP430FR6989 microcontroller.

## Docker Image

The Docker image `msp430-gcc-9.3.1.11` contains:
- `msp430-gcc`: GCC compiler for MSP430 microcontrollers
- Debugging tools and utilities

## Continuous Integration and Continuous Deployment (CI/CD)

We are planning to use a CI/CD pipeline to automate the process of building, testing, and debugging the software architecture for the MSP430FR6989 MCU. This ensures a consistent and reliable development workflow, enabling rapid iteration and deployment.
