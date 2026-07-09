# Morse Code Translator

An Arduino-based Morse Code Translator built using an Arduino Uno and two push buttons. The project converts physical button inputs into Morse code and automatically translates them into text using Arduino C++.

## Features

- Short and long press detection using `millis()`
- Button-based Morse code input
- Dot (.) and dash (-) generation
- Letter and word separation
- Automatic translation after 4 seconds of inactivity
- Serial Monitor output

## Hardware Used

- Arduino Uno
- 2 Push Buttons
- Breadboard
- Jumper Wires

## How It Works

- Button 1:
  - Short press → Dot (.)
  - Long press → Dash (-)

- Button 2:
  - Short press → End current letter
  - Long press → Space between words

After no input is detected for 4 seconds, the entered Morse code is translated and displayed on the Serial Monitor.

## Project Demo

Demo video:
[https://drive.google.com/file/d/1tKrJHOgAjjHJVZN-FGOucxRbKU_bXLcJ/view?usp=drive_link](https://drive.google.com/file/d/1tKrJHOgAjjHJVZN-FGOucxRbKU_bXLcJ/view?usp=drive_link)

## Documentation

Detailed project documentation, design decisions, debugging process, and learning notes:

[https://drive.google.com/file/d/14PUGCPBf7XXhG61r1z1l2H6GUgXHqe1J/view?usp=sharing](https://drive.google.com/file/d/14PUGCPBf7XXhG61r1z1l2H6GUgXHqe1J/view?usp=sharing)
