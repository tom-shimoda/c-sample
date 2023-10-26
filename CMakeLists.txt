cmake_minimum_required(VERSION 3.26)
project(c_sample C)

set(CMAKE_C_STANDARD 17)

add_compile_options(-D WINDOWS)
#add_compile_options(-D MAC)

add_executable(c_sample main.c
        Sample/Object-oriented/Staff.h
        Sample/Object-oriented/Staff.c
        Sample/Object-oriented/Object-oriented.c
        Sample/Object-oriented/Object-oriented.h
        Sample/Sample.c
        Sample/Sample.h
        Sample/Thread/Thread.c
        Sample/Thread/Thread.h
        Sample/Math/Rotate2D.c
        Sample/Math/Rotate2D.h
        Sample/Math/Complex.h
        Sample/Math/Vector2.h
        Sample/Math/Complex.c
        Sample/Math/Vector2.c
        Sample/Math/MathUtil.h
        Sample/Interface/IFile.h
        Sample/Interface/File.h
        Sample/Interface/File.c
        Sample/Interface/InterfaceSample.c
        Sample/Interface/InterfaceSample.h
        Sample/Coroutine/CoroutineSample.c
        Sample/Coroutine/CoroutineSample.h
        Sample/Coroutine/Coroutine.h
)
