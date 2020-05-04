# Quechua's Revenge
Small game created by Alec Ferrari, Raphael Risser, Sophie Tromello de Santis and Guillaume Robin.

This is a die and retry / rogue-like game created thanks to the C binding of a C++ library SFML.
You can find it [here](https://www.sfml-dev.org/download/csfml/index-fr.php CSFML).

#Installation
Install your version of the CSFML library and make sure you have gcc on your computer as well.
Use the command `make` to compile the game then `./my_rpg` to launch it an play.

#Known problems
Sometimes you can't exit the settings screen. We don't know where is the problem but are trying to fix it
There is a valgrind error on some computer caused by an uninitialised value but it seems to originate from the `sfTexture_createFromFile`.
We are still trying to figure out why is it caused only on some computers and not others.
