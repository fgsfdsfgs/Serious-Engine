#include <Engine/Base/PSVita/FakeExports.h>
struct ShaderDesc;

/* defs */

extern "C" void Shader_Desc_LavaDisplace(ShaderDesc &shDesc);
extern "C" void Shader_Desc_Reflection(ShaderDesc &shDesc);
extern "C" void Shader_Add(void);
extern "C" void Shader_Desc_Add(ShaderDesc &shDesc);
extern "C" void Shader_Desc_Translucent(ShaderDesc &shDesc);
extern "C" void Shader_ReflectionAndSpecular(void);
extern "C" void Shader_Translucent(void);
extern "C" void Shader_AddDS(void);
extern "C" void Shader_Desc_ReflectionDS(ShaderDesc &shDesc);
extern "C" void Shader_Desc_BaseDS(ShaderDesc &shDesc);
extern "C" void Shader_Base_TransparentDS(void);
extern "C" void Shader_Base(void);
extern "C" void Shader_Specular(void);
extern "C" void Shader_Desc_ReflectionAndSpecularDS(ShaderDesc &shDesc);
extern "C" void Shader_ReflectionAndSpecularDS(void);
extern "C" void Shader_LavaDisplace(void);
extern "C" void Shader_Desc_Base_Transparent(ShaderDesc &shDesc);
extern "C" void Shader_Desc_Base(ShaderDesc &shDesc);
extern "C" void Shader_Desc_Invisible(ShaderDesc &shDesc);
extern "C" void Shader_Reflection(void);
extern "C" void Shader_Desc_MultiLayer(ShaderDesc &shDesc);
extern "C" void Shader_SpecularDS(void);
extern "C" void Shader_Desc_AddDS(ShaderDesc &shDesc);
extern "C" void Shader_Base_Transparent(void);
extern "C" void Shader_Desc_Detail(ShaderDesc &shDesc);
extern "C" void Shader_Desc_Base_TransparentDS(ShaderDesc &shDesc);
extern "C" void Shader_ReflectionDS(void);
extern "C" void Shader_Invisible(void);
extern "C" void Shader_Desc_ReflectionAndSpecular(ShaderDesc &shDesc);
extern "C" void Shader_Desc_Color(ShaderDesc &shDesc);
extern "C" void Shader_Color(void);
extern "C" void Shader_Desc_SpecularDS(ShaderDesc &shDesc);
extern "C" void Shader_MultiLayer(void);
extern "C" void Shader_Desc_Specular(ShaderDesc &shDesc);
extern "C" void Shader_BaseDS(void);
extern "C" void Shader_Detail(void);

/* exports */

static CFakeLib exp_Shaders("Shaders", {
  { "Shader_Specular", (void*)&Shader_Specular }, 
  { "Shader_Reflection", (void*)&Shader_Reflection }, 
  { "Shader_Translucent", (void*)&Shader_Translucent }, 
  { "Shader_Color", (void*)&Shader_Color }, 
  { "Shader_Desc_ReflectionAndSpecularDS", (void*)&Shader_Desc_ReflectionAndSpecularDS }, 
  { "Shader_ReflectionAndSpecularDS", (void*)&Shader_ReflectionAndSpecularDS }, 
  { "Shader_Desc_SpecularDS", (void*)&Shader_Desc_SpecularDS }, 
  { "Shader_Desc_Base_Transparent", (void*)&Shader_Desc_Base_Transparent }, 
  { "Shader_Base", (void*)&Shader_Base }, 
  { "Shader_Desc_Base_TransparentDS", (void*)&Shader_Desc_Base_TransparentDS }, 
  { "Shader_Detail", (void*)&Shader_Detail }, 
  { "Shader_Add", (void*)&Shader_Add }, 
  { "Shader_BaseDS", (void*)&Shader_BaseDS }, 
  { "Shader_Desc_LavaDisplace", (void*)&Shader_Desc_LavaDisplace }, 
  { "Shader_Desc_BaseDS", (void*)&Shader_Desc_BaseDS }, 
  { "Shader_Invisible", (void*)&Shader_Invisible }, 
  { "Shader_ReflectionAndSpecular", (void*)&Shader_ReflectionAndSpecular }, 
  { "Shader_Desc_Translucent", (void*)&Shader_Desc_Translucent }, 
  { "Shader_AddDS", (void*)&Shader_AddDS }, 
  { "Shader_Desc_Base", (void*)&Shader_Desc_Base }, 
  { "Shader_Desc_Reflection", (void*)&Shader_Desc_Reflection }, 
  { "Shader_ReflectionDS", (void*)&Shader_ReflectionDS }, 
  { "Shader_Base_TransparentDS", (void*)&Shader_Base_TransparentDS }, 
  { "Shader_Desc_AddDS", (void*)&Shader_Desc_AddDS }, 
  { "Shader_Desc_ReflectionAndSpecular", (void*)&Shader_Desc_ReflectionAndSpecular }, 
  { "Shader_LavaDisplace", (void*)&Shader_LavaDisplace }, 
  { "Shader_Desc_Invisible", (void*)&Shader_Desc_Invisible }, 
  { "Shader_Base_Transparent", (void*)&Shader_Base_Transparent }, 
  { "Shader_Desc_Color", (void*)&Shader_Desc_Color }, 
  { "Shader_Desc_Specular", (void*)&Shader_Desc_Specular }, 
  { "Shader_Desc_Add", (void*)&Shader_Desc_Add }, 
  { "Shader_Desc_Detail", (void*)&Shader_Desc_Detail }, 
  { "Shader_Desc_ReflectionDS", (void*)&Shader_Desc_ReflectionDS }, 
  { "Shader_Desc_MultiLayer", (void*)&Shader_Desc_MultiLayer }, 
  { "Shader_SpecularDS", (void*)&Shader_SpecularDS }, 
  { "Shader_MultiLayer", (void*)&Shader_MultiLayer }, 
});
