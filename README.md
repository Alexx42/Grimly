# Grimly
Finding the fastest path to solve a maze.

## Installation
```bash
git clone [project]
```

```bash
make && make clean
```

## Usage

Since the program is able to read a map from the standard input, you can put a map as an argument or not.

```bash
./grimly [map]
```

If the algorithm is not able to find a path, or if the map is wrong, it will return an error message as following:

```bash
./grimly non_existing_map
MAP ERROR
```

## Example
```bash
./grimly resources/01.map
10x10* o12
**1*******
* o    * *
* o*   ***
* oo *   *
*  o*    *
*  oo    2
* * o    *
*   o *  *
*** o  ***
****2*****
RESULT IN 10 STEPS!
```


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
