# FdF

[![Build Status](https://travis-ci.org/joemccann/dillinger.svg?branch=master)](https://travis-ci.org/joemccann/dillinger)

FdF is the first graphics project at School 42. It is a 3D wireframe renderer that reads numeric files.

### Objective

In this project you will discover the basics of graphic programming, and in particular how to place points in space, how to join them with segments and most importantly how to observe the scene from a particular viewpoint.
You will also discover your first graphic library: miniLibX. This library was developed
internally and includes the minimum necessary to open a window, light a pixel and deal
with events linked to this window: keyboard and mouse. This project introduces you to
“events” programming. Don’t forget to watch the e-learning videos!

### Execution

FdF's minilibx requires you to be on MacOSX

```sh
$ make
$ ./fdf test_maps/[insert any map]
```

### Note
Error handling on file content has not been implemented yet.
E.g. a row with incorrect number of columns or vice versa (not a complete map)
