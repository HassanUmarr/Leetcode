int romanToInt(char* s) {
// map roman numeral to the values
    int value(char c) {
        switch (c) {
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0; 
    }
//
    int total = 0;
    int i = 0;

    while (s[i] != '\0') {
        int curr = value(s[i]);
        int next = value(s[i + 1]);
// subtractive case
        if (next > curr) {
            total += (next - curr);
            i +=2;
        } else {
            total += curr;
            i++;
        }
    }

    return total;
}
