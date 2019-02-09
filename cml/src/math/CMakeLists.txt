add_library(math OBJECT
  old/trigonometric.c
  old/hyperbolic.c

  _poleval.c
  
  _built.c
  _basic.c
  _classification.c
  
  atan.c
  atanh.c
  cos.c
  exp.c
  expm1.c
  floor.c
  frexp.c
  ldexp.c
  log.c
  pow.c
  sin.c
)
