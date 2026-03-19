#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/**
    STL 문법 재연습, 벡터
*/
void VectorFunc()
{
    vector<int> v2 = { 1, 2, 3, 4, 5 };

    for (int num : v2)
    {
        cout << num << " "; // 1 2 3 4 5;
    }

    cout << endl;

    vector<int> dyVec;
    dyVec.push_back(1);
    dyVec.push_back(2);
    dyVec.push_back(3);

    for (int i : dyVec)
    {
        cout << i << " "; // 1 2 3
    }

    cout << endl;

    vector<int> original = { 10, 20, 30 };
    vector<int> copied = original; // 복사 생성자
    vector<int> filled(5, 100);     // 5개의 요소를 100으로 초기화

    for (int val : copied)
    {
        cout << val << " "; // 10 20 30
    }

    cout << endl;

    for (int val : filled)
    {
        cout << val << " "; // 100 100 100 100 100
    }

    cout << endl;

    vector<int> vec = { 1, 2, 3, 4, 5 };
    vec[2] = 10; // 인덱스 2의 값을 10으로 변경

    for (int num : vec)
    {
        cout << num << " "; // 1 2 10 4 5
    }
    cout << endl;


    vec = { 1, 2, 3, 4, 5 };
    
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] % 2 == 0)
        {
            vec[i] = 0;
        }
    }

    for (int num : vec)
    {
        cout << num << " "; // 1 0 3 0 5
    }

    cout << endl;


}

/**
    벡터 중간삽입
*/
void VectorInsertFunc()
{
    vector<int> vec = { 1, 2, 3, 4, 5 };

    // 성능 안좋은 중간삽입
    vec.insert(vec.begin() + 2, 99); // 인덱스 2(3)에 99 삽입

    for (int num : vec)
    {
        cout << num << " "; // 1 2 99 3 4 5
    }

    // 시간복잡도는 O(n)입니다. 삽입 위치 이후의 모든 요소를 한 칸씩 이동해야 하기 때문입니다.
    cout << endl;
}

/**
    벡터 메모리 재할당
*/
void VectorReallocFunc()
{
    vector<int> vec;
    cout << "초기 용량: " << vec.capacity() << endl; // 초기 용량

    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        cout << "현재 크기: " << vec.size() << ", 현재 용량: " << vec.capacity() << endl;
    }

    /*
        출력결과 예시 (환경마다 다를 수 있음)
        size: 1, capacity: 1
        size: 2, capacity: 2
        size: 3, capacity: 4
        size: 4, capacity: 4
        size: 5, capacity: 8
        ...
        유의사항: 용량(capacity)을 초과하면 2배씩 재할당 → 이 과정은 O(N)
    */
     
    cout << endl;

    vector<int> vec2;
    vec2.reserve(10); // 최대 10개 원소 요소 저장, 미리 메모리 확보
    cout << "초기 용량: " << vec2.capacity() << endl; // 초기 용량

    for (int i = 0; i < 10; ++i)
    {
        vec2.push_back(i);
        cout << "현재 크기: " << vec2.size() << ", 현재 용량: " << vec2.capacity() << endl;
    }

    cout << endl;
}

/**
    STL 문법 재연습, 셋
*/
void SetFunc()
{
    set<int> Set = { 3, 1, 3, 2, 5 };

    for (int v : Set)
    {
        cout << v << " ";
    }

    cout << endl;

    // 출력결과: 1 2 3 5
    // 중복된 3은 제거되고 자동으로 오름차순 정렬됨

    set<int> s;

    s.insert(5);
    s.insert(2);
    s.insert(2); // 중복 삽입 시도
    s.insert(8);

    for (int v : s) 
    {
        cout << v << " ";
    }

    cout << endl;
    // 출력결과: 2 5 8
    // 중복된 2는 한 번만 저장됨, 자동 오름차순 정렬

    set<int> s1 = { 7, 3, 1 };
    set<int> s2 = s1; // s1 복사

    for (int v : s2) 
    {
        cout << v << " ";
    }
    // 출력결과: 1 3 7
    // 복사된 셋도 오름차순 정렬 유지

    cout << endl;

    s = { 1, 2, 3, 4, 5 };
    s.erase(3); // 3 삭제
    s.erase(10); // 없는 값 삭제 시 무시됨

    for (int v : s) {
        cout << v << " ";
    }

    cout << endl;

    s = { 1, 2, 3, 4, 5 };
    s.clear(); // 모든 원소 삭제
    cout << "Size after clear: " << s.size() << endl;

    cout << endl;

    s = { 1, 2, 3, 4, 5 };
    // 3을 30으로 변경하려면, 먼저 3을 삭제하고 30 삽입
    s.erase(3);
    s.insert(30);

    // 출력결과: 1 2 4 5 30
    // 원소를 직접 수정할 수 없기 때문에 반드시 erase + insert 필요
    for (int v : s) {
        cout << v << " ";
    }

    cout << endl;

}

/**
    STL 문법 복습, 맵
*/
void MapFunc()
{
    map<string, double> studentGrades = { {"John", 3.7}, {"Emma", 3.9}, {"Sophia", 4.0} };

    // map의 아이템은 pair 단위로 순회해야 한다.
    for (auto& pair : studentGrades) // auto& pair : map 객체는 pair<string, double> 타입의 요소로 순회
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << endl;
    // Emma: 3.9
    // John: 3.7
    // Sophia: 4.0
    // 주의: 키(이름)가 알파벳 순으로 자동 정렬됨
    // unordered_map을 사용하면 해시 기반으로 저장되어 삽입 순서 유지, 키 정렬 없음

    map<string, int> m1 = { {"Dog", 1}, {"Cat", 2} };
    map<string, int> m2 = m1; // m1을 복사
    
    for (auto& p : m2) 
    {
        cout << p.first << ": " << p.second << endl;
    }

    // 출력결과:
    // Cat: 2
    // Dog: 1
    // 복사된 map도 자동으로 키 순서 정렬 유지
    cout << endl;

    map<string, int> myMap = { {"Apple", 1}, {"Banana", 2}, {"Cherry", 3} };
    myMap["Apple"] = 10;   // 기존 키의 값 변경
    myMap["Durian"] = 4;   // 새로운 키-값 쌍 추가
    

    for (auto& p : myMap) 
    {
        cout << p.first << ": " << p.second << endl;
    }

    // 출력결과:
    // Apple: 10
    // Banana: 2
    // Cherry: 3
    // Durian: 4
    // [] 연산자는 키가 없을 경우 새로 추가함

    cout << endl;

    map<int, string> myMap2;

    auto result1 = myMap2.insert({ 1, "Apple" });
    auto result2 = myMap2.insert({ 2, "Banana" });
    auto result3 = myMap2.insert({ 1, "Cherry" }); // 중복 키

    cout << "삽입 1 성공 여부: " << result1.second << endl; // true
    cout << "삽입 2 성공 여부: " << result2.second << endl; // true
    cout << "삽입 3 대상" << result3.first->first << ": " << result3.first->second << endl; // 1: Apple
    cout << "삽입 3 (중복) 성공 여부: " << result3.second << endl; // false
    
    for (auto& p : myMap2) 
    {
        cout << p.first << ": " << p.second << endl;
    }

    cout << endl;

    // 출력결과:
    // 삽입 1 성공 여부: 1
    // 삽입 2 성공 여부: 1
    // 삽입 3 (중복) 성공 여부: 0
    // 1: Apple
    // 2: Banana

    map<int, string> myMap3 = { {1, "Apple"}, {2, "Banana"}, {3, "Cherry"} };

    myMap3.erase(2); // 키 2 삭제

    auto it = myMap3.find(3); // 키 3의 반복자 찾기
    if (it != myMap3.end())
    {
        myMap3.erase(it); // 반복자를 이용한 삭제
    }

    for (auto& p : myMap3) 
    {
        cout << p.first << ": " << p.second << endl;
    }

    cout << endl;

    // 출력결과:
    // 1: Apple
    // 키 기반 삭제는 O(logN), 반복자 삭제는 평균 O(1)

    map<int, string> myMap4 = { {1, "Apple"}, {2, "Banana"}, {3, "Cherry"} };
    myMap.clear(); // 전체 삭제

    cout << "Size after clear: " << myMap.size() << endl;

}

/**
    STL 문법 복습, 알고리즘
*/
void AlgorithmFunc()
{
    vector<int> vec = { 5, 2, 9, 1, 7 };

    sort(vec.begin(), vec.end()); // 오름차순 정렬

    for (int v : vec)
    {
        cout << v << " "; // 1 2 5 7 9
    }

    cout << endl;

    auto comp = [](int a, int b) { return a > b; }; // 내림차순 비교 함수
    //bool (*comp)(int, int) = [](int a, int b) { return a > b; }; // 함수 포인터로도 사용 가능
    
    sort(vec.begin(), vec.end(), comp); // 내림차순 정렬

    for (int v : vec)
    {
        cout << v << " "; // 9 7 5 2 1
    }

    cout << endl;

    auto compareByLength = [](const string& a, const string& b)
        {
            return a.length() < b.length(); // 짧은 문자열이 앞에 오도록 정렬
        };

    vector<string> names = { "Alice", "Bob", "Christina", "Dan" };
    sort(names.begin(), names.end(), compareByLength);

    for (const string& name : names)
    {
        cout << name << " "; // Dan Bob Alice Christina
    }

    cout << endl;

    // find 알고리즘
    vec = { 10, 20, 30, 40, 50 };

    auto it = find(vec.begin(), vec.end(), 30); // 30을 찾는 반복자 반환

    if (it != vec.end()) // 실패 시 end() 반환
    {
        cout << "찾은 값: " << *it << endl; // 찾은 값: 30
    }

    cout << endl;

    it = find(vec.begin(), vec.end(), 99); // 99는 없음
    if (it == vec.end())
    {
        cout << "값을 찾을 수 없습니다." << endl; // 값이 없다는 메시지 출력
    }
    cout << endl;

    // Count 알고리즘
    vector<int> v = { 1, 5, 2, 5, 3, 4 };

    int result = count(v.begin(), v.end(), 5); // 5의 개수 세기
    cout << "5의 개수: " << result << endl; // 5의 개수: 2

    cout << endl;

    result = count(v.begin(), v.end(), 10); // 10은 없음
    cout << "10의 개수: " << result << endl; // 10의 개수: 0
    // 존재하지 않으면 0 반환

    cout << endl;

    // Unique 알고리즘
    // unique()는 범위 [first, last] 내에서 연속된 중복 요소를 제거합니다.

    /*
        단, 실제로 컨테이너에서 원소가 삭제되는 것은 아니며, 각 원소의 첫 번째 발생만 유지되도록 원소들을 앞쪽으로 덮어씌워 재배열합니다.

        그 이후의 영역은 남아 있으므로(어떻게 남는지는 undefiend), 
        보통 `erase()`와 함께 사용하여 완전히 제거합니다.
        (`erase–remove idiom`)
    */

    v = { 1, 1, 2, 2, 2, 3, 1, 1 };
    auto newEnd = unique(v.begin(), v.end()); // 연속된 중복 제거

    for (auto it = v.begin(); it != newEnd; ++it)
    {
        cout << *it << " "; // 1 2 3 1
    }
    // 출력결과: 1 2 3 1
    // 주의: 실제 컨테이너 크기는 그대로이고, 중복 제거된 결과는 앞쪽에만 있음

    cout << endl;
    
    v = { 1, 1, 2, 2, 2, 3, 1, 1 };
    
    unique(v.begin(), v.end());

    for (int val : v) {
        cout << val << " ";
    }

    cout << endl;
    // 출력결과: 1 2 3 3 3 3 3 (이후 값이 남아있음)
    // ⚠️ 원소가 "논리적으로"만 제거됨. 실제 삭제된 건 아님.

    v = { 1, 1, 2, 2, 2, 3, 1, 1 };
    
    v.erase(unique(v.begin(), v.end()), v.end()); // 중복 제거 후 남은 영역 삭제
    // v에서(newEnd , v.end()) 범위를 삭제하는 것이므로 앞 부분은 유지되고 중복 제거된 결과만 남게 됨

    for (int val : v)
    {
        cout << val << " "; // 1 2 3
    }

    cout << endl;
}

int main()
{
    // 벡터 사용법
    VectorFunc();

    // 벡터 중간삽입
    VectorInsertFunc();

    // 벡터 할당 / 재할당
    VectorReallocFunc();

    // 셋 사용법
    SetFunc();

    // 맵 사용법
    MapFunc();

    // STL 알고리즘 사용법
    AlgorithmFunc();

    return 0;
}

