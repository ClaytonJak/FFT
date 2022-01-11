#include "freq_classifier.h"

std::string freq_classify(double in_freq) {
	std::string out_string;
    if (in_freq >= 1000000000.) {
        out_string = std::to_string(in_freq / 1000000000.);
        out_string.append(" GHz");
    }
    else if (in_freq >= 10000000.) {
        out_string = std::to_string(in_freq / 1000000.);
        out_string.append(" MHz");
    }
    else if (in_freq >= 10000000.) {
        out_string = std::to_string(in_freq / 1000000.);
        out_string.append("  MHz");
    }
    else if (in_freq >= 1000000.) {
        out_string = std::to_string(in_freq / 1000000.);
        out_string.append("   MHz");
    }
    else if (in_freq >= 100000.) {
        out_string = std::to_string(in_freq / 1000.);
        out_string.append(" kHz");
    }
    else if (in_freq >= 10000.) {
        out_string = std::to_string(in_freq / 1000.);
        out_string.append("  kHz");
    }
    else if (in_freq >= 1000.) {
        out_string = std::to_string(in_freq / 1000.);
        out_string.append("   kHz");
    }
    else {
        out_string = std::to_string(in_freq);
        out_string.append("  Hz");
    }
	return out_string;
}