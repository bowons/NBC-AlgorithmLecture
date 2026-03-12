#include <iostream>
#include <cmath>
#include <sstream>
#include <string>

void RoundFunc()
{
    double num1 = 3.2;
    double num2 = 3.5;
    double num3 = 3.8;

    std::cout << round(num1) << std::endl; // 3
    std::cout << round(num2) << std::endl; // 4
    std::cout << round(num3) << std::endl; // 4
}

void CeilFunc()
{
    double a = 3.2;
    double b = -3.2;

    std::cout << ceil(a) << std::endl; // 4
    std::cout << ceil(b) << std::endl; // -3 (더 큰 정수로 올림
}

void FloorFunc()
{
    // 동작: 실수 값을 내림하여 주어진 숫자보다 작거나 같은 가장 큰 정수로 변환

    double a = 3.7;
    double b = -3.7;

    std::cout << floor(a) << std::endl; // 3
    std::cout << floor(b) << std::endl; // -4 (더 작은 정수로 내림
}

// stringstream 공백 기준으로 분리
/**
    이 방식은 cin을 사용할 때 기본적으로 공백 단위로 입력을 받았던 것과 유사합니다.
    우선, 분리할 문자열을 stringstream의 생성자에 전달하여 입력 스트림으로 설정합니다.

    그 후 >>연산자를 이용해 문자열에서 원하는 데이터를 차례대로 변수에 저장합니다.
    이 과정을 그림으로 표현하면 아래와 같습니다.
*/
void SpaceSplitFunc()
{
    std::string str = "123 X 67";
    std::stringstream stream(str);

    int num;
    char c;
    float f;

    stream >> num >> c >> f;

    std::cout << num << std::endl; // 123
    std::cout << c << std::endl;   // X
    std::cout << f << std::endl;   // 67
}

// 특정 문자 기준으로 분리
/**
    이번엔 단순한 공백이 아닌 특정 문자 기준으로 분리하는 방법을 살펴보겠습니다.
    기본적인 원리는 이전과 비슷하지만, 공백 대신 문자로 구분하기 위해서는 getline 함수를 사용할 수 있습니다.

    `getline(입력 스트림, 토큰을 저장할 문자열 변수 ,  구분자 문자)`

    예를 들어, **“,”**를 기준으로 문자열을 분리하려면 `getline(ss, buf, ‘,’)`와 같이 사용할 수 있습니다.
    일반적으로 `while` 반복문과 함께 사용하여 문자열을 끝까지 순차적으로 분리합니다.
*/
void SplitByCharFunc()
{
    std::string text = "apple,banana,grape,orange";
    std::stringstream ss(text);
    std::string token;

    while (getline(ss, token, ','))
    {
        std::cout << token << std::endl; // apple, banana, grape, orange
    }
}

// 진법 변환(16진수↔10진수)
/**
    10진수를 16진수로 변환하는 과정입니다.
    10진수를 16진수로 변환할 때는 기존 변수 출력 스트림을 통해 넣어야 하므로 stringstream과 <<연산자를 활용합니다.

    즉, stringstream 객체에 << 연산자를 이용해 값을 출력하면, 내부적으로 해당 값이 문자열로 저장되며 이때 hex 조작자를 함께 사용하면 자동으로 16진수 형식으로 변환됩니다.
*/
void DecToHexFunc()
{
    int decimalNumber = 4095;
    std::stringstream ss;

    // 1) 10 -> 16
    ss << std::hex << decimalNumber; // 16진수로 변환하여 스트림에 저장
    std::string hexStr = ss.str(); // 스트림에서 문자열로 추출

    std::cout << "원본 10진수 : " << decimalNumber << std::endl;
    std::cout << "16진수 문자열: " << hexStr << std::endl;
}

/**
    16진수를 10진수로 변환하는 과정입니다.
    stringstream을 이용해 16진수 형식의 문자열을 읽고, 그 값을 정수형 변수에 저장해야 하므로 >> 연산자를 사용합니다.

    이때 stringstream에 hex 조작자를 설정해두면, 내부 문자열이 16진수로 해석되어 올바르게 정수로 변환될 수 있습니다.
*/
void HexToDecFunc()
{
    std::string hexStr = "ff";
    std::stringstream ss(hexStr);
    int decimalNumber;

    // 16진수 형태로 파싱하도록 조작자를 설정
    ss >> std::hex >> decimalNumber;

    std::cout << "16진수: " << hexStr << std::endl;
    std::cout << "10진수: " << decimalNumber << std::endl;

}

int main()
{
    // round 함수 사용
    RoundFunc();
    // ceil 함수 사용
    CeilFunc();
    // floor 함수 사용
    FloorFunc();

    // stringstream을 이용한 공백 기준 분리
    SpaceSplitFunc();

    // stringstream을 이용한 특정 문자 기준 분리
    SplitByCharFunc();

    // 10진수 → 16진수 변환
    DecToHexFunc();

    // 16진수 → 10진수 변환
    HexToDecFunc();
}

