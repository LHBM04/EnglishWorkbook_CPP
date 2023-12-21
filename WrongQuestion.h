#pragma once

template <typename TQuestion>
class WrongQuestion : requires TQuestion public Question{
private:
	TQuestion m_wrongQuestion;

};

