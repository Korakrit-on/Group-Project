#include <stdio.h>
#include <string.h> // ใช้สำหรับเช็คตัวอักษร

#define MAX 100

// ฟังก์ชันลบตัวเลขและเครื่องหมายที่คำนวณเสร็จแล้ว (เขยิบ Array)
void deleteElement(double nums[], char ops[], int index, int *count) {
    for (int i = index + 1; i < *count; i++) {
        nums[i] = nums[i + 1];
    }
    for (int i = index; i < *count - 1; i++) {
        ops[i] = ops[i + 1];
    }
    (*count)--;
}

// ฟังก์ชันคำนวณตาม "กลุ่มเครื่องหมาย" ที่ระบุ
// เช่น ส่ง "+-" มา แปลว่าเจอ + หรือ - ให้ทำเลย (ใครมาก่อนทำก่อน)
void process(double nums[], char ops[], int *count, const char *validOps) {
    int i = 0;
    while (i < *count - 1) {
        char currentOp = ops[i];
        
        // เช็คว่าเครื่องหมายปัจจุบัน อยู่ในกลุ่มที่เราต้องการทำตอนนี้ไหม?
        // เช่น validOps = "+-" ถ้า currentOp เป็น '+' หรือ '-' ก็จะทำงาน
        if (strchr(validOps, currentOp) != NULL) {
            double val1 = nums[i];
            double val2 = nums[i+1];
            double res = 0;

            if (currentOp == '*') res = val1 * val2;
            else if (currentOp == '/') res = (val2 != 0) ? val1 / val2 : 0;
            else if (currentOp == '%') res = (int)val1 % (int)val2;
            else if (currentOp == '+') res = val1 + val2;
            else if (currentOp == '-') res = val1 - val2;

            nums[i] = res; // ใส่ผลลัพธ์แทนที่
            deleteElement(nums, ops, i, count); // ลบตัวที่ใช้แล้ว
            // ไม่ต้อง i++ เพราะข้อมูลไหลมาแทนที่ตำแหน่งเดิมแล้ว
        } else {
            i++; // ถ้าไม่ใช่เครื่องหมายในกลุ่มนี้ ให้ข้ามไปดูตัวถัดไป
        }
    }
}

int main() {
    double nums[MAX];
    char ops[MAX];
    int count = 0;

    printf("--- Calculator (Standard: 179 Correct Logic) ---\n");
    printf("Logic: (* / %%) First, then (+ -) Left-to-Right\n");
    printf("Enter expression: ");

    // รับค่าตัวเลขแรก
    scanf("%lf", &nums[count++]);

    // ลูปรับค่าทั้งหมด
    while (1) {
        char c;
        scanf("%c", &c);
        if (c == '\n') break;
        if (c == ' ') continue;

        ops[count-1] = c;
        scanf("%lf", &nums[count++]);
    }

    // --- ส่วนสำคัญที่แก้ไข ---
    
    // รอบที่ 1: จัดการกลุ่มคูณ หาร เศษ ก่อน (Priority สูง)
    // คุณสามารถแยก process(..., "*") แล้วค่อย process(..., "/") ก็ได้ถ้าอยากให้คูณชนะหารขาดลอย
    // แต่มาตรฐานคือทำกลุ่มนี้ก่อน
    process(nums, ops, &count, "*/%"); 

    // รอบที่ 2: จัดการกลุ่ม บวก และ ลบ (Priority ต่ำ)
    // หัวใจสำคัญ: ส่ง "+-" เข้าไปพร้อมกัน เพื่อให้มันทำจาก ซ้ายไปขวา
    process(nums, ops, &count, "+-");

    printf("Result: %.2lf\n", nums[0]);

    return 0;
}