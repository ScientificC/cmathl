add_library(math OBJECT
  old/nearest-integer.c
  old/trigonometric.c
  old/power.c
  old/exponential.c
  old/hyperbolic.c

  _poleval.c
  
  _built.c
  _basic.c
  _classification.c
  
  sin.c
  cos.c
)
