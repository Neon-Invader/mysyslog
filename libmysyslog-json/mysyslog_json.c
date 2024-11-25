#include <stdio.h>
#include <time.h>
#include <json-c/json.h>

void log_json(const char* msg, int level, const char* process) 
{
    json_object* jobj = json_object_new_object();
    json_object_object_add(jobj, "timestamp", json_object_new_int(time(NULL)));
    json_object_object_add(jobj, "log_level", json_object_new_int(level));
    json_object_object_add(jobj, "process", json_object_new_string(process));
    json_object_object_add(jobj, "message", json_object_new_string(msg));

    printf("%s\n", json_object_to_json_string(jobj));

    json_object_put(jobj);  // Освобождение памяти
}
