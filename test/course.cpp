#include "course.h"

void Course::calculateFinalScore() {
    if (labScore == -1) {
        // 无实验：综合成绩 = 平时成绩*30% + 卷面成绩*70%
        finalScore = regularScore * 0.3 + examScore * 0.7;
    } else {
        // 有实验：综合成绩 = 平时成绩*15% + 实验成绩*15% + 卷面成绩*70%
        finalScore = regularScore * 0.15 + labScore * 0.15 + examScore * 0.7;
    }
}

void Course::calculateActualCredit() {
    if (finalScore >= 90) {
        actualCredit = credit * 1.0;
    } else if (finalScore >= 80) {
        actualCredit = credit * 0.8;
    } else if (finalScore >= 70) {
        actualCredit = credit * 0.75;
    } else if (finalScore >= 60) {
        actualCredit = credit * 0.6;
    } else {
        actualCredit = 0.0;
    }
}
