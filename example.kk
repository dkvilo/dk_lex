struct person_t {
  str name;
  i32 age;
}

person_new :: (str name, i32 age) person_t {
  struct person_t p = {
    .name = name,
    .age = age
  };
  return p;
}

struct person_t p = person_new(name = "John", age = 30);
println(p.name);

main :: (i32 x, i32 y) i32 {
  return x + y;
}

// Call main with (1, 2)
main(1, 3, "Hello, World");

enum MY_ENUMS : i32 {
  ONE,
  TWO,
  THREE,
  FOUR,
  FIVE,
  SIX,
}

str name = "David";
i32 age = 23;
str occupation = "Programmer";
str address = "Tbilisi, Georgia";
bool is_available = false;
i32 result = age + 2;

str color = "darkgreen";
if is_available {
  str hello = "world";
}

if is_available {
  str my_string = "This is a relatively long string";
  if some_condition < 0 {
    i32 x = 1;
  }
}

import "example.kk";

mod fs {
  read_file       :: (str path) str;
  write_file      :: (str path, str content) i32;
  delete_file     :: (str path) i32;
  rename_file     :: (str old_path, str new_path) i32;
  copy_file       :: (str old_path, str new_path) i32;
  move_file       :: (str old_path, str new_path) i32;
  stat_file       :: (str path) str;
  mkdir           :: (str path) i32;
  rmdir           :: (str path) i32;
  read_dir        :: (str path) str;
  stat_dir        :: (str path) str;
  mkdir_recursive :: (str path) i32;
  rmdir_recursive :: (str path) i32;
} use fs;

mod net {
  get_ip           :: () str;
  get_mac          :: () str;
  get_hostname     :: () str;
  get_domain       :: () str;
  get_gateway      :: () str;
  get_dns          :: () str;
  get_ip_address   :: () str;
  get_ip_netmask   :: () str;
  get_ip_broadcast :: () str;
  get_ip_gateway   :: () str;
  get_ip_dns       :: () str;
  get_ip_dhcp      :: () str;
}

mod os {
  get_os_name      :: () str;
  get_os_version   :: () str;
  get_os_arch      :: () str;
  get_os_platform  :: () str;
  get_os_distro    :: () str;
  get_os_release   :: () str;
  get_os_codename  :: () str;
  get_os_type      :: () str;
}

mod time {
  get_time         :: () str;
  get_time_utc     :: () str;
  get_time_local   :: () str;
  get_time_zone    :: () str;
}

mod date {
  get_date         :: () str;
  get_date_utc     :: () str;
  get_date_local   :: () str;
  get_date_zone    :: () str;
}

mod ogl {
  get_opengl_version :: () str;
  get_opengl_vendor :: () str;
  get_opengl_renderer :: () str;
  get_opengl_shading_language_version :: () str;
  get_opengl_extensions :: () str;
}

mod testing {
  assert :: (bool condition, str message) i32;
}

mod util {
  str_to_i32       :: (str s) i32;
  i32_to_str       :: (i32 i) str;
  str_to_bool      :: (str s) bool;
}

mod std {
  println          :: (str s, ...) void;
  print            :: (str s, ...) void;
}

mod math {
  add             :: (i32 x, i32 y) i32;
  sub             :: (i32 x, i32 y) i32;
  mul             :: (i32 x, i32 y) i32;
  div             :: (i32 x, i32 y) i32;
  pow             :: (i32 x, i32 y) i32;
  sqrt            :: (i32 x) i32;
  abs             :: (i32 x) i32;
  min             :: (i32 x, i32 y) i32;
  max             :: (i32 x, i32 y) i32;
  clamp           :: (i32 x, i32 min, i32 max) i32;
  clamp_float     :: (f32 x, f32 min, f32 max) f32;
  lerp            :: (i32 x, i32 y, f32 t) i32;
  lerp_float      :: (f32 x, f32 y, f32 t) f32;
  sin             :: (f32 x) f32;
  cos             :: (f32 x) f32;
  tan             :: (f32 x) f32;
  asin            :: (f32 x) f32;
  acos            :: (f32 x) f32;
  atan            :: (f32 x) f32;
  atan2           :: (f32 x, f32 y) f32;
  sinh            :: (f32 x) f32;
  cosh            :: (f32 x) f32;
  tanh            :: (f32 x) f32;
  asinh           :: (f32 x) f32;
  acosh           :: (f32 x) f32;
  atanh           :: (f32 x) f32;
  deg_to_rad      :: (f32 x) f32;
  rad_to_deg      :: (f32 x) f32;
}


x :: i32 = 1; // this is constant
y :: i32 = 2; // this is constant


for i32 i = 0; i < 10; i = i + 1 {
  use std;
  use math;
  println("Hello, World!");
  printf("Hello, World 10 times");
}

use testing;
assert(x == 1, "x is not 1");

struct system_ctx_t;



