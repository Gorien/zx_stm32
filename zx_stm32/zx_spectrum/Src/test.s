#include "zx.h"

//Экспортируем asm_func
.global sub2
//и говорим, что где-то есть нужный нам символ global_var
// - наша глобальная переменная
.extern global_var

sub2:		SUB r0, r0, r1
			BX lr

