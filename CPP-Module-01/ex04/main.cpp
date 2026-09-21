#include <fstream>
#include <iostream>
#include <string>

static std::string replaceAll(const std::string &line, const std::string &from,
	const std::string &to)
{
	std::string result;
	std::string::size_type start = 0;
	std::string::size_type found;

	while ((found = line.find(from, start)) != std::string::npos)
	{
		result.append(line, start, found - start);
		result += to;
		start = found + from.length();
	}
	result.append(line, start, std::string::npos);
	return (result);
}

int main(int argc, char **argv)
{
	if (argc != 4 || std::string(argv[2]).empty())
	{
		std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>"
			<< std::endl;
		return (1);
	}
	std::ifstream input(argv[1]);
	if (!input)
	{
		std::cerr << "Error: cannot open input file." << std::endl;
		return (1);
	}
	const std::string outputName = std::string(argv[1]) + ".replace";
	std::ofstream output(outputName.c_str());
	if (!output)
	{
		std::cerr << "Error: cannot create output file." << std::endl;
		return (1);
	}
	std::string line;
	while (std::getline(input, line))
	{
		output << replaceAll(line, argv[2], argv[3]);
		if (!input.eof())
			output << '\n';
	}
	if (input.bad() || !output)
	{
		std::cerr << "Error: file operation failed." << std::endl;
		return (1);
	}
	return (0);
}
