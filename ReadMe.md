
# Mongo-Bench

## Purpose

Very simple import test from standard input for MongoDB.

Creates a large number of JSON lines for 1 second which can be piped to the *mongoimport* command.


## Compilation

`gcc mongoimporter.c -o mb -O3 -Wall -s`

`gcc mongoimporter.c -o mb.exe -O3 -Wall -s`


## Usage

`mb | mongoimport --db junk --collection years --drop`

`mb.exe | mongoimport --db junk --collection years --drop`


### License

Mongo-Bench is released under the [GPL v.3](https://www.gnu.org/licenses/gpl-3.0.html).
