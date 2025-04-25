#pragma once

class Subject;
class Observer {
public:
	virtual ~Observer() = default;
	virtual void update(Subject *sbj) = 0;
};