#pragma once

class IntegerMatrix
{
  protected:
    int n; // Rows
    int m; // Columns
    unsigned int **datas;

  public:
    IntegerMatrix() : n{0}, m{0}, datas{nullptr}
    {
    }

    IntegerMatrix(unsigned int **datas, int n, int m) : datas{datas}, n{n}, m{n}
    {
    }

    IntegerMatrix(const IntegerMatrix &other) : datas{other.datas}, n{other.n}, m{other.m}
    {
    }

    ~IntegerMatrix()
    {
        for (int i = 0; i < n; i++)
            delete[] datas[i];
        delete[] datas;

        n = m = 0;
    }

    auto operator&(const IntegerMatrix &rhs) -> IntegerMatrix
    {
        IntegerMatrix tmp{*this};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp.datas[i][j] &= rhs.datas[i][j];
            }
        }

        return tmp;
    }

    auto operator|(const IntegerMatrix &rhs) -> IntegerMatrix
    {
        IntegerMatrix tmp{*this};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp.datas[i][j] |= rhs.datas[i][j];
            }
        }

        return tmp;
    }

    auto operator^(const IntegerMatrix &rhs) -> IntegerMatrix
    {
        IntegerMatrix tmp{*this};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp.datas[i][j] ^= rhs.datas[i][j];
            }
        }

        return tmp;
    }

    auto operator=(const IntegerMatrix &other) -> IntegerMatrix &
    {
        this->~IntegerMatrix();

        this->m = other.m;
        this->n = other.n;
        this->datas = new unsigned int *[other.n];
        for (int i = 0; i < n; i++)
        {
            this->datas[i] = new unsigned int[other.m];
        }

            for (int i = 0; i < other.n; i++)
            {
                for (int j = 0; j < other.m; j++)
                {
                    this->datas[i][j] = other.datas[i][j];
                }
            }

        return *this;
    }

    auto operator*(int rhs) -> IntegerMatrix
    {
        IntegerMatrix tmp{*this};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp.datas[i][j] &= rhs;
            }
        }

        return tmp;
    }

    auto operator+(int rhs) -> IntegerMatrix
    {
        IntegerMatrix tmp{*this};

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                tmp.datas[i][j] |= rhs;
            }
        }

        return tmp;
    }

    auto canonical() const -> IntegerMatrix {}
};

class BoolMatrix : public IntegerMatrix
{
  public:
    BoolMatrix() : IntegerMatrix{}
    {
    }

    BoolMatrix(unsigned int **datas, int n, int m) : IntegerMatrix{datas, n, m}
    {
    }

    BoolMatrix(const BoolMatrix &other) : IntegerMatrix{other}
    {
    }

    ~BoolMatrix()
    {
    }

    auto units() const -> int
    {
        auto count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (datas[i][j] == 1)
                    count++;
            }
        }
    }
};
