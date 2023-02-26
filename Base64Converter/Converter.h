#pragma once
#include <string>
#include <iostream>
#include <vector>

const char fillchar = '=';

// 00000000001111111111222222
// 01234567890123456789012345
static std::string  cvt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

// 22223333333333444444444455
// 67890123456789012345678901
"abcdefghijklmnopqrstuvwxyz"

// 555555556666
// 234567890123
"0123456789+/";

static const std::string base64_chars =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz"
"0123456789+/";

static inline bool is_base64(unsigned char c) {
	return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(const std::string& text_str) {
	const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

	std::vector<unsigned char> bytes(text_str.begin(), text_str.end());

	std::string base64_str;
	size_t padding = 0;
	for (size_t i = 0; i < bytes.size(); i += 3) {
		unsigned int value = bytes[i] << 16;
		if (i + 1 < bytes.size()) {
			value |= bytes[i + 1] << 8;
		}
		if (i + 2 < bytes.size()) {
			value |= bytes[i + 2];
		}

		base64_str += base64_chars[(value >> 18) & 0x3F];
		base64_str += base64_chars[(value >> 12) & 0x3F];
		if (i + 1 < bytes.size()) {
			base64_str += base64_chars[(value >> 6) & 0x3F];
		}
		else {
			base64_str += '=';
			padding++;
		}
		if (i + 2 < bytes.size()) {
			base64_str += base64_chars[value & 0x3F];
		}
		else {
			base64_str += '=';
			padding++;
		}
	}

	return base64_str.substr(0, base64_str.length() - padding);
}


std::string base64_decode(std::string const& encoded_string) {
	int in_len = encoded_string.size();
	int i = 0;
	int j = 0;
	int in_ = 0;
	unsigned char char_array_4[4], char_array_3[3];
	std::string ret;

	while (in_len-- && (encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
		char_array_4[i++] = encoded_string[in_]; in_++;
		if (i == 4) {
			for (i = 0; i < 4; i++)
				char_array_4[i] = base64_chars.find(char_array_4[i]);

			char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
			char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
			char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

			for (i = 0; (i < 3); i++)
				ret += char_array_3[i];
			i = 0;
		}
	}

	if (i) {
		for (j = i; j < 4; j++)
			char_array_4[j] = 0;

		for (j = 0; j < 4; j++)
			char_array_4[j] = base64_chars.find(char_array_4[j]);

		char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
		char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
		char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

		for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
	}

	return ret;
}

std::string textToBase64(std::string text) {
	std::string base64 = base64_encode(text);
	return base64;
}

std::string base64ToText(std::string base64) {
	std::string text = base64_decode(base64);
	return text;
}