#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Shape abstract
{
public:
	Shape() {};
	~Shape() {
	
	};
	virtual void show() const = 0;
	virtual void save(const string& fname) const = 0;
	virtual void load(const string& fname) = 0;
};
class Square: public Shape
{
public:
	Square() = default;
	Square(const int& x, const int& y, const size_t& side) : x{ x }, y{ y }, side{side} {
	};
	virtual void show() const override {
		cout << "\t---------Square---------" << endl;
		cout << "coordinates: " << x << ", " << y << "\tSide: " << side << endl;
	}
	virtual void save(const string& fname) const override {
		fstream fs;
		fs.open(fname, ios::out | ios::in | ios::app);
		if (!fs.is_open())
			cout << "failed to open " << fname << '\n';
		else {
			fs << "s" << x << " " << y << " " << side << endl;
		}
		fs.close();
	}
	virtual void load(const string& fname) override {
		ifstream fs(fname);
		if (fs.fail()) {
			cout << "fail to load" << endl;
			return;
		}
		string line;
		while (getline(fs, line))
		{
			if (line.at(0) == 's') {
				break;
			}
			line = "";
		}
		convert(line);
	}
private:
	void convert(string line) {
		string number = "";
		string numbers = line.erase(0, 1);
		vector<int> vec;
		for (auto x : numbers) {
			if (x == ' ') {
				vec.push_back(stoi(number));
				number = "";
			}
			else {
				number += x;
			}
		}
		vec.push_back(stoi(number));
		x = vec[0];
		y = vec[1];
		side = vec[2];
	}
	int x, y;
	size_t side;
};


class Rectangle : public Shape
{
public:
	Rectangle() = default;
	Rectangle(const int& x, const int& y, const size_t& hight, const size_t& width) : x{ x }, y{ y }, hight{ hight }, width{width} {
	};
	virtual void show() const override {
		cout << "\t---------Rectangle---------" << endl;
		cout << "coordinates: " << x << ", " << y << "\tHight: " << hight << "\tWidth: " << width << endl;
	}
	virtual void save(const string& fname) const override {
		fstream fs;
		fs.open(fname, ios::out | ios::in |ios::app);
		if (!fs.is_open())
			cout << "failed to open " << fname << '\n';
		else {
			fs << "r" << x << " " << y << " " << hight << " " << width << endl;
		}
		fs.close();
	}
	virtual void load(const string& fname) override {
		ifstream fs(fname);
		if (fs.fail()) {
			cout << "fail to load" << endl;
			return;
		}
		string line;
		while (getline(fs, line))
		{
			if (line.at(0) == 'r') {
				break;
			}
			line = "";
		}
		convert(line);
	}
private:
	void convert(string line) {
		string number = "";
		string numbers = line.erase(0, 1);
		vector<int> vec;
		for (auto x : numbers) {
			if (x == ' ') {
				vec.push_back(stoi(number));
				number = "";
			}
			else {
				number += x;
			}
		}
		vec.push_back(stoi(number));
		x = vec[0];
		y = vec[1];
		hight = vec[2];
		width = vec[3];
	}
	int x, y;
	size_t hight;
	size_t width;
};

class Circle : public Shape
{
public:
	Circle() = default;
	Circle(const int& x, const int& y, const size_t& radius) : x{ x }, y{ y }, radius{ radius } {
	};
	virtual void show() const override {
		cout << "\t---------Circle---------" << endl;
		cout << "coordinates: " << x << ", " << y << "\tRadius: " << radius << endl;
	}
	virtual void save(const string& fname) const override {
		fstream fs;
		fs.open(fname, ios::out | ios::in | ios::app);
		if (!fs.is_open())
			cout << "failed to open " << fname << '\n';
		else {
			fs << "c" << x << " " << y << " " << radius << endl;
		}
		fs.close();
	}
	virtual void load(const string& fname) override {
		ifstream fs(fname);
		if (fs.fail()) {
			cout << "fail to load" << endl;
			return;
		}
		string line;
		while (getline(fs, line))
		{
			if (line.at(0) == 'c') {
				break;
			}
			line = "";
		}
		convert(line);
	}
private:
	void convert(string line) {
		string number = "";
		string numbers = line.erase(0, 1);
		vector<int> vec;
		for (auto x : numbers) {
			if (x == ' ') {
				vec.push_back(stoi(number));
				number = "";
			}
			else {
				number += x;
			}
		}
		vec.push_back(stoi(number));
		x = vec[0];
		y = vec[1];
		radius = vec[2];
	}
	int x, y;
	size_t radius;
};

class Ellipse : public Shape
{
public:
	Ellipse() = default;
	Ellipse(const int& x, const int& y, const size_t& hight, const size_t& width) : x{ x }, y{ y }, hight{ hight }, width{ width } {
	};
	virtual void show() const override {
		cout << "\t---------Ellipse---------" << endl;
		cout << "coordinates: " << x << ", " << y << "\tHight: " << hight << "\tWidth: " << width << endl;
	}
	virtual void save(const string& fname) const override {
		fstream fs;
		fs.open(fname, ios::out | ios::in | ios::app);
		if (!fs.is_open())
			cout << "failed to open " << fname << '\n';
		else {
			fs << "e" << x << " " << y << " " << hight << " " << width << endl;
		}
		fs.close();
	}
	virtual void load(const string& fname) override {
		ifstream fs(fname);
		if (fs.fail()) {
			cout << "fail to load" << endl;
			return;
		}
		string line;
		while (getline(fs, line) )
		{
			if (line.at(0) == 'e') {
				break;
			}
			line = "";
		}
		convert(line);
	}
private:
	void convert(string line) {
		string number = "";
		string numbers = line.erase(0, 1);
		vector<int> vec;
		for (auto x : numbers) {
			if (x == ' ') {
				vec.push_back(stoi(number));
				number = "";
			}
			else {
				number += x;
			}
		}
		vec.push_back(stoi(number));
		x = vec[0];
		y = vec[1];
		hight = vec[2];
		width = vec[3];
	}
	int x, y;
	size_t hight;
	size_t width;
};

int main()
{
	vector<Shape*> vec = { new Square(1, 2, 5), new Rectangle(3, 4, 15, 10), new Circle(2, 1, 30), new Ellipse(0, 0, 4, 8)};
	for (auto& item : vec) {
		item->save("data.txt");
	}
	vector<Shape*> newvec = {new Square(), new Rectangle(), new Circle(), new Ellipse()};
	for (auto& item : newvec) {
		item->load("data.txt");
		item->show();
	}
	remove("data.txt");
}
