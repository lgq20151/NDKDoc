//
// Created by 103style on 2019/8/15.
//


#include <jni.h>
#include "com_example_myapplication_MainActivity.h"

JNIEXPORT jstring JNICALL Java_com_example_myapplication_MainActivity_helloNDK
        (JNIEnv *env, jobject) {
    return env->NewStringUTF("Hello NDK");
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_accessField(JNIEnv *env, jobject instance) {
    //获取类
    jclass jcla = env->GetObjectClass(instance);
    //获取类的成员变量showText的id
    jfieldID jfId = env->GetFieldID(jcla, "showText", "Ljava/lang/String;");

    jstring after = env->NewStringUTF("Hello NDK");
    //修改属性id对应的值
    env->SetObjectField(instance, jfId, after);
}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_myapplication_MainActivity_accessStaticField(JNIEnv *env, jobject instance) {
    //获取类
    jclass oClass = env->GetObjectClass(instance);
    //获取静态变量id
    jfieldID staticFid = env->GetStaticFieldID(oClass, "staticString", "Ljava/lang/String;");

    //设置静态属性值
    jstring after = env->NewStringUTF("static field update in jni");
    env->SetStaticObjectField(oClass, staticFid, after);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_accessMethod(JNIEnv *env, jobject instance) {
    //获取类
    jclass jCla = env->GetObjectClass(instance);
    //获取方法id  第二个参数：方法名  第三个参数：(参数)返回值 的类型描述
    jmethodID methodID = env->GetMethodID(jCla, "getAuthName",
                                          "(Ljava/lang/String;)Ljava/lang/String;");
    jstring res = env->NewStringUTF("103style");
    jobject objRes = env->CallObjectMethod(instance, methodID, res);
    return static_cast<jstring>(objRes);
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_myapplication_MainActivity_accessStaticMethod(JNIEnv *env, jobject instance) {

}