#include <stdio.h>
#include <json-c/json.h>
 
int main(void) 
{
    struct json_object *obj = json_object_new_object();
 
    json_object_object_add(obj, "name", json_object_new_string("xiaoming"));
 
    // 创建json数组对象
    struct json_object *array = json_object_new_array();
    json_object_array_add(array, json_object_new_int(99));
    json_object_array_add(array, json_object_new_int(100));
 
    // 把数组对象添加到json对象中
    json_object_object_add(obj, "score", array);
 
    printf("%s\n", json_object_to_json_string(obj));
 
    struct json_object *json;
    json_object_object_get_ex(obj, "score", &json);
    if (json_object_get_type(json) == json_type_array) 
    {
        int i;
        // 获取json_type_array类型json对象长度
        int size = json_object_array_length(json);
        for (i = 0; i < size; i++) 
        {
            // 根据下标提取json对象
            struct json_object *j = json_object_array_get_idx(json, i); 
            if (json_type_int == json_object_get_type(j)) 
            {
                printf("%d\n", json_object_get_int(j));
            }
        }
    }
    return 0;
}