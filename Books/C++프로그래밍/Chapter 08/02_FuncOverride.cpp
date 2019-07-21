/************
<주소>		: p344
**********
<해결방안>	:

StaticType *ptr = new DynamicType();
일 때, DynamicType은 StaticType이거나, 그것을 상속하는 클래스여야 함!

또한 C++ 컴파일러는 포인터 자료형을 통해 연산 가능성 여부를 판단하기 때문에 Static Type에 맞는 연산만 가능!
만약 오버라이딩 된 함수가 있다면, 그것 역시 Static Type에 해당하는 함수를 호출하게 된다.

**********
<오답노트>	:

*/
