add_library (MathFunctions mysqrt.c)

# add install targets
install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
