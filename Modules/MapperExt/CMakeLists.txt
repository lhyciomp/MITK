mitk_create_module(
  DEPENDS MitkDataTypesExt MitkLegacyGL
)

if(TARGET ${MODULE_TARGET})
  if(MITK_USE_OpenMP)
    target_link_libraries(${MODULE_TARGET} PUBLIC OpenMP::OpenMP_CXX)
  endif()

  if(BUILD_TESTING)
    add_subdirectory(test)
  endif()
endif()
