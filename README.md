# NERF HIT ORDER PUZZLE

### This is a puzzle that uses hardware and software to create an engaging puzzle that acts as one puzzle inside a larger escape room.

## The User experience:

- The user, with a toy nerf gun that was unlocked previously, shoots at the board of three uniquely size circular cutouts (targets).
- When any target is hit a grouping of LEDs will flash and then leave one LED still lit to indeicate a counter of total hits.
- The user has to hit all targets in the correct order (correct order being from largets to smallest targets).
- Wrong Order: The LEDs will flash red and a buzzer will make unpleasent beeping sounds. The board will be reset with all LEDs being in the off position.
- Correct Order: All the LEDs will flash green and the buzzer will play a "successful" sounding series of beeps. The microprocessor will then signal to the 5v relay to allow the connected 12v electric lock to release (slide down a track) a physical key towards the customer. This key will then be used to progress on to the next puzzle in the room.

## The Hardware:

- Peizo Vibration sensors.
- Arduino Nano.
- 5v Relays.
- 12v Locks.
- LEDs (Red, Green).
- Peizo buzzer.

## The Software:

- Code written by myself using arduino IDE, C++.
- Libraries:
- none.

<img src="./NerfProgressPuzzle.gif" dynsrc="./NerfProgressPuzzle.gif" loop=infinite alt="shooting nerfs at board animated gif" width="250" class="rounded float-left img-thumbnail">
