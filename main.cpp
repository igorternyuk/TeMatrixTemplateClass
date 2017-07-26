#include <matrix.h>

using namespace std;
using namespace iat;

bool foo(int, int);
//int N = 5;
std::vector<std::vector<double>> bar()
{
    std::vector<std::vector<double>> lhs = {{-1, 7},{9, -20}};
    return lhs;
}

int main()
{

    Matrix<double> mtrA("A.txt");
    cout << "Matrix A:\n" << mtrA << endl;
    cout << "Matrix<row 1> A:\n" << mtrA.getRow(1) << endl;
    cout << "Matrix.rowCount A:\n" << mtrA.getRowCount() << endl;
    cout << "Matrix<col 2> A:\n" << mtrA.getColumn(2) << endl;
    cout << "Matrix.colCount A:\n" << mtrA.getColumnCount() << endl;
    cout << "pow(mtrA, 5):\n" << mtrA.power(5) << endl;
    mtrA += 5;
    cout << "mtrA += 5:\n" << mtrA << endl;
    mtrA -= 5;
    cout << "mtrA -= 5:\n" << mtrA << endl;
    mtrA *= 10;
    cout << "mtrA *= 10:\n" << mtrA << endl;
    mtrA /= 5;
    cout << "mtrA /= 5:\n" << mtrA << endl;
    Matrix<double> mtrB("B.txt");
    bool isSwapSuccessfull = mtrA.swapColumns(0, 1);
    cout << "isSwapSuccessfull:\n" << isSwapSuccessfull << endl;
    cout << "mtrA.swapColumns(0, 1):\n" << mtrA << endl;
    cout << "Matrix B:\n" << mtrB << endl;
    mtrB.swapRows(0, 1);
    cout << "mtrB.swapRows(0, 1):\n" << mtrB << endl;
    mtrB.swapElements(0, 0, 2, 2);
    cout << "mtrB.swapElements(0, 0, 2, 2):\n" << mtrB << endl;
    cout << "--------------Asignment operators----------------" << endl;
    cout << "mtrA:\n" << mtrA << endl;
    cout << "mtrB:\n" << mtrB << endl;
    mtrA += mtrB;
    cout << "mtrA += mtrB => mtrA:\n" << endl;
    cout << mtrA << endl;
    mtrA -= mtrB;
    cout << "mtrA -= mtrB => mtrA:\n" << endl;
    cout << mtrA << endl;
    mtrA *= mtrB;
    cout << "mtrA *= mtrB => mtrA:\n" << endl;
    cout << mtrA << endl;
    cout << "A - B = " << endl;
    cout << mtrA - mtrB << endl;
    cout << "B * A = " << endl;
    cout << mtrB * mtrA << endl;
    cout << "Det = " << mtrA.determinant() << endl;
    cout << "Rank = " << mtrA.rank() << endl;
    cout << "a22 = " << mtrA[2][2] << endl;
    cout << "Transposed matrix:" << endl;
    cout << mtrA.transpose() << endl;
    cout << "Inversed matrix:" << endl;
    cout << mtrA.inverse() << endl;
    //cout << mtrA.inverse() << endl;
    cout << "mtrA[0][0] = 999:" << endl;
    mtrA[0][0] = 999;
    cout << mtrA.inverse() << endl;
    cout << mtrA.inverse() << endl;
    cout << mtrA.inverse() << endl;
    cout << "Inversed Inversed matrix:" << endl;
    cout << mtrA.inverse().inverse() << endl;
    mtrA.setValueAt(0, 0, 300);
    cout << "a00 was set to 300:" << endl;
    cout << mtrA << endl;
    cout << "a22 = " << mtrA.getValueAt(2, 2) << endl;
    cout << "a_max = " << mtrA.maxElement() << endl;
    cout << "a_min = " << mtrA.minElement() << endl;
    /*mtr.fillByRandomNumbers(-10, 20);
    cout << "Mtr was filled by random numbers" << endl;
    cout << mtr << endl;*/
    cout << "old Matrix A:\n" << mtrA << endl;
    cout << "old Matrix B:\n" << mtrB << endl;
    mtrA.swap(mtrB);
    cout << "************swap A and B **************" << endl;
    cout << "new Matrix A:\n" << mtrA;
    cout << "new Matrix B:\n" << mtrB;
    cout << "B * B^-1 = " << endl;
    cout << mtrB.transpose() * mtrB.transpose().inverse() << endl;
    Matrix<double> mtrC("C.txt");
    cout << "C = " << endl;
    cout << mtrC << endl;
    try
    {
        //cout << mtrC.inverse() << endl;
        cout << "A + C = " << endl;
        cout << mtrA + mtrC << endl;
    }
    catch (exception &ex)
    {
        cout << ex.what() << endl;
    }

    cout << "C + 100 = " << endl;
    cout << mtrC + 100.0 << endl;
    cout << "++C = " << endl;
    cout << ++mtrC << endl;
    cout << "--C = " << endl;
    cout << --mtrC << endl;
    mtrA = mtrC;
    cout << "Присвоили A <- C" << endl;
    cout << "A = " << endl;
    cout << mtrA << endl;
    cout << "C = " << endl;
    cout << mtrC << endl;
    cout << "A != C : " << (mtrA != mtrC) << endl;
    try
    {
        Matrix<double> mtrD("D.txt");
        ofstream fo("res.txt");
        fo << mtrD.transpose() << endl;
        fo.close();
        cout << mtrD.inverse() << endl;
    }
    catch(exception &err)
    {
        cout << err.what() << endl;
    }

    Matrix<double> mtrF("F.txt");
    cout << "F = " << endl;
    cout << mtrF<< endl;
    Matrix<double> mtrE("E.txt");
    cout << "E = " << endl;
    cout << mtrE << endl;
    cout << "mtrF * mtrE = " << endl;
    cout << mtrF * mtrE << endl;
    mtrE *= mtrF;
    cout << "mtrE *= mtrF " << endl;
    cout << mtrE << endl;

    Matrix<complex<double>> complMtr(3, 3, complex<double>(1,1));
    cout << "complMtr before= " << endl << complMtr << endl;
    complMtr[0][0] = complex<double>(200,-5);
    complMtr[1][1] = complex<double>(14.17,300);
    complMtr[2][2] = complex<double>(100,5);
    cout << "complMtr after = " << endl << complMtr << endl;
    cout << "row0 = " << complMtr.getRow(0) << endl;
    cout << "col1 = \n" << complMtr.getColumn(1) << endl;

    Matrix<double> mtrK("K.txt");
        cout << "K = " << endl;
        cout << mtrK<< endl;

    cout << "***************Search all elements of the main diagonal**************" << endl;
    std::vector<std::tuple<int, int, double>> results = mtrK.find_if([&](int i, int j){
        return i == j;
    });

    for(auto e: results)
    {
        cout << "({" << std::get<0>(e) << "," << std::get<1>(e) <<
                "}->" << std::get<2>(e) << ")" << std::endl;
    }

    cout << "***************Search all elements of the secondary diagonal**************" << endl;
    results = mtrK.find_if([&](int i, int j){
        return i + j == mtrK.getColumnCount() - 1;
    });

    //std::vector<std::tuple<int, int, double>> results = mtrK.find_if(&foo);

    for(auto e: results)
    {
        cout << "({" << std::get<0>(e) << "," << std::get<1>(e) <<
                "}->" << std::get<2>(e) << ")" << std::endl;
    }
    cout << endl;

    cout << "***************VECTORS**************" << endl;

    Matrix<double> vct1(1, 3, 1);
    for(int i = 0; i < vct1.getColumnCount(); ++i)
       vct1[0][i] = 1;
    cout << "Vector1:\n" << vct1 << endl;
    cout << "vct1.norm() = " << vct1.norm() << endl;
    cout << "vct1.modulus()= " << vct1.norm() << endl;
    Matrix<double> vct2(1, 3, 2);
    for(int i = 0; i < vct2.getColumnCount(); ++i)
       vct2[0][i] = (i + 1) * (i + 1);
    cout << "Vector2:\n" << vct2 << endl;
    cout << "vct2.norm() = " << vct2.norm() << endl;
    cout << "vct2.modulus()= " << vct2.norm() << endl;
    cout << "Dot product = " << dotProduct(vct1, vct2) << endl;
    cout << "Cross product = " << crossProduct(vct1, vct2) << endl;
    cout << "Direction cosines = \n" << vct1.directionCosines() << endl;
    vct1[0][0] = 2;
    vct1[0][1] = 0;
    vct1[0][2] = 0;
    cout << "Vector1:\n" << vct1 << endl;
    vct2[0][0] = 2;
    vct2[0][1] = 2;
    vct2[0][2] = 0;
    cout << "Vector2:\n" << vct2 << endl;
    cout << "angleBetweenVectors = " << endl << angleBetweenVectors(vct1, vct2) << endl;
    Matrix<double> vct3(3, 1, 1);
    vct3[0][0] = 5;
    vct3[1][0] = 0;
    vct3[2][0] = 0;
    cout << "Vector3:\n" << vct3 << endl;
    Matrix<double> vct4(3, 1, 1);
    vct4[0][0] = -5;
    vct4[1][0] = 5;
    vct4[2][0] = 0;
    cout << "Vector4:\n" << vct4 << endl;
    cout << "angleBetween column-vectors = " << endl << angleBetweenVectors(vct3, vct4) << endl;
    Matrix<int> entityMtr(5, true);
    cout << "identity = \n" << entityMtr << endl;
    cout << "isIdentity = \n" << entityMtr.isIdentity() << endl;
    cout << "isisZero = \n" << entityMtr.isZero()<< endl;
    Matrix<double> vct5(3, 1, 1);
    vct5[0][0] = 1;
    vct5[1][0] = 1;
    vct5[2][0] = 1;
    cout << "Vector5:\n" << vct5 << endl;
    Matrix<double> vct6(3, 1, 1);
    vct6[0][0] = 1;
    vct6[1][0] = 2;
    vct6[2][0] = -51;
    cout << "Vector5:\n" << vct6 << endl;
    Matrix<double> vct7(3, 1, 1);
    vct7[0][0] = 7;
    vct7[1][0] = 3.14;
    vct7[2][0] = 100;
    cout << "Vector7:\n" << vct7 << endl;
    cout << "vectorTripleProduct = \n" << vectorTripleProduct(vct5, vct6, vct7) << endl;
    Matrix<double> mtrOfSystem(2, 2, 1);
    mtrOfSystem[0][0] = -1;
    mtrOfSystem[0][1] = 7;
    mtrOfSystem[1][0] = 9;
    mtrOfSystem[1][1] = -20;
    Matrix<double> rightSight(2, 1, 1);
    rightSight[0][0] = 9;
    rightSight[1][0] = 5;
    Matrix<double> resultado = mtrOfSystem.solveEquationSystem(rightSight);
    cout << resultado << endl;
    Matrix<double> orth(2, 2, 1);
    cout << "--------------Orthogonal matrix----------------" << endl;
    double angle(M_PI / 4);
    orth[0][0] = cos(angle);
    orth[0][1] = sin(angle);
    orth[1][0] = -sin(angle);
    orth[1][1] = cos(angle);
    cout << "Rotation matrix:\n" << orth << endl;
    cout << "orth_inverse:\n" << orth.inverse() << endl;
    cout << "orth_transpose:\n" << orth.transpose() << endl;
    cout << "orth_det:\n" << orth.determinant() << endl;
    cout << "orth_rank:\n" << orth.rank() << endl;
    cout << "orth_isOrthogonal:\n" << orth.isOrthogonal() << endl;
    cout << "orth_isZero:\n" << orth.isZero() << endl;
    cout << "orth_isIdentity:\n" << orth.isIdentity() << endl;
    cout << "orth_isQuadratic:\n" << orth.isQuadratic() << endl;
    Matrix<double> oldCoords(2, 1, 1);
    oldCoords[0][0] = 10;
    oldCoords[1][0] = 7;
    cout << "oldCoords:\n" << oldCoords << endl;
    cout << "newCoords:\n" << orth * oldCoords << endl;
    cout << "--------------String stream----------------" << endl;
    ostringstream ss;
    ss << mtrOfSystem;
    cout << ss.str();
    Matrix<double> M1(mtrB.inverse());
    cout << "M1 = \n" << M1 << endl;
    Matrix<double> M2(M1.inverse());
    cout << "M2 = \n" << M2 << endl;
    M1 *= M2;
    cout << "M1 *= M2\n" << M1 << endl;
    cout << "sqrt(-1) = " << sqrt(-1) << endl;
    cout << "--------------Constructor with vector paramenter----------------" << endl;
    std::vector<std::vector<double>> lhs = {{-1, 7},{9, -20}};
    Matrix<double> mtrFromVct(bar());
    cout << "left hand side of  res = \n" << mtrFromVct << endl;
    std::vector<std::vector<double>> rhs = {{9},{5}};
    Matrix<double> rhs_(rhs);
    cout << "mtrFromVct res = \n" << mtrFromVct.solveEquationSystem(rhs_) << endl;
    //double xx = 5.6;
    //cout << "XX /0" << xx / 0;
    return 0;
}

bool foo(int i, int j)
{
   return i + j == 5 - 1;
}
