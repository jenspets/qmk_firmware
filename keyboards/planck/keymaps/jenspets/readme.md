# Jenspets' keymap for the Planck keyboard

## Background
The keymap is based on a common 34-key layout, with the extra keys acting as "convenience keys" for often used keys.

## Base 34-key layout
The base 34-key layout is defined in the file users/jenspets/jenspets.h. 
It uses 10 layers, which are documented in users/jenspets/readme.md.

## Convenience keys
The convenience keys are typical keys that are often used, and nice to have available. They are the rest of the 14 keys on the keyboard. 

The letter "J" is placed so it is reachable for the thumbs. There are many words with "kj" and "hj" bigrams in Norwegian, and these are inconvenient to type in a Colemak layout. 

## Wide layout
The keymap uses by default a wide layout, that moves each half of the characters to each side and have the convenience keys in the middle two columns. This makes the hands have a better angle when writing. 

To use an ordinary layout, remove definition of "USE_WIDE_MOD" from config.h. 

## Color-coded layers
The backlight is used for indicating keymap. The layer colors are calculated from the hue of the base layer. This makes it easy to see which layer is active. 

The color codes are hard coded in users/jenspets/jenspets.c

## Swap hands
Swap hands is set up at space/ backspace keys, such that holding space or backspace will mirror the keyboard. I did use this more before, but I have not updated this after implementing homerow mods. 

In order to make the swap hands more functional, the modifier keys should not be mirrored, such that all modifier/key combinations is reachable on both hands. This has not currently been implemented. 

The swap hands functionality can be enabled by setting SWAP_HANDS_ENABLE to "true" in rules.mk.
