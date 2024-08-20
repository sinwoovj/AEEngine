//#pragma once
//
///*
//Manager 클래스
//•    관리: 특정 유형의 컴포넌트를 관리.
//•    싱글톤: 특정 유형의 매니저는 한 번에 하나만 존재.
//•    업데이트: 특정 유형의 모든 컴포넌트를 업데이트.
//o    특정 유형의 컴포넌트가 생성될 때 매니저에 추가.
//•    컨테이너: 컴포넌트들을 위한 컨테이너.
//업데이트 호출
//•    GSM 레벨에서 업데이트 등을 호출합니다.
//컴포넌트 예시
//•    Transform 컴포넌트: GO의 위치, 회전, 크기를 가집니다.
//•    로직 컴포넌트: 시뮬레이션 수행.
//o    동작 출력.
//o    다른 객체 접근.
//o    이동 등.
//•    Sprite 컴포넌트: 객체를 그립니다.
//•    Audio 컴포넌트: 오디오를 재생합니다.
//*/
//class Manager
//{
//	//Copy constructor
//	Manager(const Manager& other) = delete;
//	//Asignment operator
//	const Manager& operator=(const Manager& other) = delete;
//	static Manager* my_ptr;
//
//protected:
//	Manager() = default;
//	~Manager() = default;
//
//public:
//
//	static Manager* GetManager();
//	static void DeletePtr();
//};