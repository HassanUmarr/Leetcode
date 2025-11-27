bool isPalindrome(int x) {
    // Negative numbers are not palindrome
    // Also numbers ending in 0, but not 0 itself can't be palindrome
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reversed = 0;

    // Reverse only half of the num
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }

    // For an odd digit count drop the middle digit ; reversed / 10
    return (x == reversed || x == reversed / 10);
}
