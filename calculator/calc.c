#include<stdio.h>
#include <stdlib.h>

// ฟังก์ชันตรวจสอบตัวเลข
double readFactor(char **p){
    // เตรียมตัวชี้สำหรับการบอกจุดสิ้นสุดตัวเลข
    char *end_ptr;

    //เอาตำแหน่งหลังจากจบตัวเลข ไปใส่ไว้ใน end_ptr
    double num = strtod(*p, &end_ptr);
    // ตรวจสอบว่ามีการอ่านตัวเลขจริงไหม (ถ้า end_ptr ขยับ แปลว่าอ่านได้)
    if (*p != end_ptr) {
        // อัปเดตตำแหน่ง pointer หลักของเรา ให้ไปอยู่ที่เดียวกับ end_ptr
        // (คือข้ามตัวเลขที่อ่านไปแล้ว)
        *p = end_ptr;
    }
    
    return num;

}


int main() {
 
}
