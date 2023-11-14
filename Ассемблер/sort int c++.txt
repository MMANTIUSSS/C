#include <iostream>
#include <time.h>
using namespace std;
void main()
{
    int dpos = 0, minpos = 0;
    short  x[1000], i, d, min, n;
    srand(time(0));
    cout << "n = ";
    cin >> n;
    for (i = 0; i < n; i++)
        x[i] = 1 + rand() % n;
    for (i = 0; i < n; i++)
        cout << x[i] << " ";
    _asm {
        mov ecx, 0
        mov cx, n
        S1 : mov ebx, dpos
        mov ax, x[ebx]
        mov d, ax

        push cx
        mov ax, d
        mov min, ax

        L0 :
        MOV ax, x[ebx]
            CMP ax, min
            JG L1
            MOV min, ax
            MOV minpos, ebx
            L1 : add ebx, 2
            loop    L0

            MOV esi, minpos
            MOV edi, dpos
            push x[esi]
            push x[edi]
            pop x[esi]
            pop x[edi]

            mov eax, 2
            add dpos, eax
            pop cx
            loop s1
    }
    cout << endl << "sorting completed: " << endl;
    for (i = 0; i < n; i++)
        cout << x[i] << " ";
}