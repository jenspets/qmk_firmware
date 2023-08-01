
# Description of Jenspets' keymap

## Copyright

Copyright 2023 Jens-Petter Sandvik jens.petter.sandvik@gmail.com @jenspets

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


## Keymap visualization
```
+----------+----------+----------+-----------+-----+------+-----------+----------+----------+-----------+
|     Q    |    W     |     F    |     P     |  B  |   J  |     L     |     U    |     Y    |     ;     |
|----------+----------+----------+-----------+-----+------+-----------+----------+----------+-----------+
|  A / GUI | R / LALT | S / CTRL | T / SHIFT |  G  |   M  | N / SHIFT | E / CTRL | I / LALT |  O / GUI  |
|----------+----------+----------+-----------+-----+------+-----------+----------+----------+-----------+
|  Z / NAV |    X     |     C    | D / ALTGR |  V  |   K  | H / ALTGR |    ,     |     .    | / / AUDIO |
+----------+----------+----------+-----------+-----+------+-----------+----------+----------+-----------+
                                 | TAB / LWR | SPC | BSPC | ESC / RSE |
                                 +-----------+-----+------+-----------+
```							 
 
## Background 

This is the common setup between keyboards for jenpets' keymaps. 

It uses a 34 key base with layers that are common between most keyboards. Currently the keymap is used on Planck, Lumberjack, and Kyria keyboards. In addition there is a keymap for the Hasu USB to USB converter for use on the HHKB Pro 2 keyboard.

The layers are:
- Colemak
- Qwerty 
- Game 
- Game 2
- Plover
- Lower
- Raise
- Audio
- Adjust
- Nav
- Num

## Description of layers

### Base layers (Colemak-DH and Qwerty)

The base layers (Colemak-DH and Qwerty) uses the homerow mods with the modifiers as GUI, ALT, CTRL, SHIFT layout with RALT/ AltGr on the bottom row. The AltGr is important for non-english language if the operating system's keymap is set to English International. In addition there are two hotkeys for temporary change layer to Lower, Raise, Adjust, Nav and Num. 

### Lower

The Lower layer is for symbols, and have often used brackets and paranthesis on left hand strong fingers, and often used other symbols on the other hand. 

### Raise 

The Raise layer includes F-keys and numbers. The numbers are laid out to maximize the amount of numbers the strongest fingers use. I assumed a uniform distribution of numbers in general, but where the first digit follows Benford's law. The implication is that the lowest digits are most used, and this is reflected in the keymap by placing the most-used numbers on the easiest-to-reach keys. 

There are toggles to the Nav and Num layer in this layer.

### Adjust

This layer have various adjustments, like light, music modes, and so on. Also, boot and reset keys are in this layer.

### Audio

This layer is for adjusting audio volume and has a few multimedia controls, making it convenient for one handed use.

### Game

The game layer is created with an one-key offset for the WASD keys to the right. This offset means that I don't need to move my hand from the home position to use WASD. An additional advantage, is that the left column can be used for tab/ctrl buttons. 

The right hand side has arrow keys in home row position, and a few keys to facilitate running Trackmania

### Game 2

This is a layer for numbers and F-keys for game layer.

### Nav 

This is a layer for navigation. It has mouse keys, arrows in a vim-type cluster at home row, page up/down, tab, and home/end. 
### Num

This is a layer for typing numbers. It has a numpad on the right hand side and mathematical symbols and arrows to navigate on the right hand. An example for this is using spreadsheets, where both navigation between cells and typing numbers.

### Plover

A layer for typing with Plover stenography. Unfortunately this needs 6 columns, while the base layout only defines 5 columns.

## Discussion on implementing keymap

### Macro to use in main keymap file

To use the keymap macros, the layout macro need to be wrapped so the macros can be expanded. 
This is from the file keyboards/planck/keymaps/jenspets/keymap.c:

	#define LAYOUT_ortho_4x12_wrap(...)  LAYOUT_ortho_4x12(__VA_ARGS__)


### Keymap variations

I use this as a base for keymaps on all the keyboards I use. The extra keys on the keyboards are used for convenience keys, e.g., enter, the letter "j", and so on. The reason for J on a convenience key, is that Norwegian has many words with the bigrams "hj" and "kj" that are very inconvenient to type in a Colemak-DH keymap. 

The Hasu usb-usb converter has an ISO-layout, but the HHKB has an ANSI layout. This means that the macros for Row 4, left hand, has to be implemented manually instead of using the XXX_R4_L macro.

## Lights
The layers have different colours based on the base color defined. Each layer change will change the backlight's hue with a set amount from the base layer color. 
