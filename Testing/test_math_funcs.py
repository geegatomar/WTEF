def add(a, b):
    return a + b


def product(a, b):
    return a * b


def test_add():
    assert add(2, 5) == 7


def test_product():
    assert product(4, 8) == 32
