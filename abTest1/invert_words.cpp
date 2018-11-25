#include "pch.h"
#include <string.h>
#include "state_machine.h"

using namespace std;

inline void swap(char* c1, char* c2) { char t = *c1; *c1 = *c2; *c2 = t; }
inline void invert_string(char *l, char *r) { while (l < r) { if (*l != *r) swap(l, r); ++l; --r; } }
void invert_words(char* s)
{
	invert_string(s, s + strlen(s) - 1);
	state_machine sm;
	sm.init(s);
	while (state_machine::END != sm.get_state())
	{
		sm.input_char();
		switch (sm.get_state())
		{
		case state_machine::END_WORD_TO_LEFT:
		case state_machine::BLANK_WORD_TO_LEFT:
			char *word; int word_length;
			sm.get_last_word(word, word_length);
			invert_string(word, word + word_length - 1);
			break;
		}
	}
}
