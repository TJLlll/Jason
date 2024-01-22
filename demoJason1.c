#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <json-c/json.h>
 
int main(void) {
    //一、创建JSON
    // 1、创建空json对象
    struct json_object *obj = json_object_new_object();
 
    // 2、往json对象里添加键值对
    json_object_object_add(obj, "name", json_object_new_string("xiaoming"));
    json_object_object_add(obj, "age", json_object_new_int(20));
 
    // 3、打印json对象的内容和长度
    printf("%s\n", json_object_to_json_string(obj));
    printf("%ld\n", strlen(json_object_to_json_string(obj)));
 
    //二、解析JSON
    // 1：根据键名解析出对应的json对象
    struct json_object *json;
    json_object_object_get_ex(obj, "name", &json);
 
    // 2：根据json对象类型转换成对应的数据
    json_type type = json_object_get_type(json);// 先获取json对象类型
    if (json_type_string == type) {
        printf("name: %s\n", json_object_get_string(json));
    }
 
    json_object_object_get_ex(obj, "age", &json);
    printf("age: %d\n", json_object_get_int(json));
 
    return 0;
}	