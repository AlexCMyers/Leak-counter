# Leak-counter
A memory leak detector/counter that intercepts calls to malloc and free, determining if memory has been cleared correctly

Memory leak tools are important in languages like C and C++ where memory management is done primarily by the developer
(as opposed to Java where it's handled automatically by the JVM)


Compile: make

Use: ./leakcount [.exe] [arg0] [arg1] [...]

Test programs included: `test` (is compiled with `make` command)
`make test` will run `./leakcount test`
