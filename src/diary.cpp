

#include "diary.h"

// your code here

Diary::Diary(const std::string& initialPassword) :
    password(initialPassword), content(""), isOpen(false) {}

Diary::~Diary() {
    if (isOpen) {
        content.clear();
        std::cout << "Дневник уничтожен, данные очищены" << std::endl;
    }
}

bool Diary::unlock(const std::string& inputPassword) {
    if (inputPassword == password) {
        isOpen = true;
        return true;
    } else {
        std::cout << "Неверный пароль" << std::endl;
        return false;
    }
}

void Diary::write(const std::string& text) {
    if (isOpen) {
        content += text;
    } else {
        std::cout << "Ошибка: дневник закрыт!" << std::endl;
    }
}

void Diary::lock() { isOpen = false; }

std::string Diary::read() {
    if (isOpen) {
        return content;
    } else {
        std::cout << "Ошибка: дневник закрыт!" << std::endl;
        return "";
    }
}
