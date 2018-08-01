#pragma once

class BG_ERROR {
public:
	enum class Common {
		BG_NONE,	// ����
		BG_ERROR,	// ����	
	};

	enum class Http {
		BG_NONE,	// ����
		BG_ERROR,	// ����
	};

	static int ErrorCode(Common error) { return static_cast<int>(error); }
	static int ErrorCode(Http error) { return static_cast<int>(error); }
};


