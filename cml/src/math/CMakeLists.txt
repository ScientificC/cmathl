add_library(math OBJECT
  old/trigonometric.c
  old/exponential.c
  old/hyperbolic.c

  _poleval.c
  
  _built.c
  _basic.c
  _classification.c
  
  atanh.c
  cos.c
  floor.c
  log.c
  pow.c
  sin.c
)
