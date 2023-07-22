include_directories(${PROJECT_SOURCE_DIR}/model/include)

add_executable(objectExample objectExample.c vehicle.c)
add_executable(inheritanceExample car.c vehicle.c inheritanceExample.c)
add_executable(arrayExample vehicle.c arrayExample.c)