#include "kdTree.hh"
#include <gtest/gtest.h>

class KDTreeTest : public ::testing::Test {
protected:
    kdTree* tree;

    // Esta función se ejecuta antes de cada prueba
    virtual void SetUp() {
        tree = new kdTree(2); // Creando un árbol de 2 dimensiones como ejemplo.
    }

    // Esta función se ejecuta después de cada prueba
    virtual void TearDown() {
        delete tree;
    }
};

TEST_F(KDTreeTest, TestConstructor) {
EXPECT_TRUE(tree);
EXPECT_TRUE(tree->empty());
EXPECT_EQ(tree->valori(0), -1); // Asumiendo que un árbol vacío retorna -1 para cualquier coordenada.
}

TEST_F(KDTreeTest, TestBasicK1InsertAndInorder) {
EXPECT_TRUE(tree);
vector<double> point1 = {0.1};
vector<double> point2 = {0.2};
vector<double> point3= {0.3};
vector<double> point4= {0.4};
vector<double> point5 = {0.5};

tree->insert(point3);
tree->insert(point2);
tree->insert(point4);
tree->insert(point5);
EXPECT_FALSE(tree->empty());
EXPECT_EQ(tree->getRoot()->x[0], 0.3);
EXPECT_EQ(tree->getRoot()->left->x[0], 0.2);
EXPECT_EQ(tree->getRoot()->right->x[0], 0.4);
EXPECT_EQ(tree->getRoot()->right->right->x[0], 0.5);
}

TEST_F(KDTreeTest, TestBasicK2InsertAndInorder) {
EXPECT_TRUE(tree);
vector<double> point1 = {0.1};
vector<double> point2 = {0.2};
vector<double> point3= {0.3};
vector<double> point4= {0.4};
vector<double> point5 = {0.5};

tree->insert(point3);
tree->insert(point2);
tree->insert(point4);
tree->insert(point5);
EXPECT_FALSE(tree->empty());
EXPECT_EQ(tree->getRoot()->x[0], 0.3);
EXPECT_EQ(tree->getRoot()->left->x[0], 0.2);
EXPECT_EQ(tree->getRoot()->right->x[0], 0.4);
EXPECT_EQ(tree->getRoot()->right->right->x[0], 0.5);
}

TEST_F(KDTreeTest, TestInsertAndInorder) {
EXPECT_TRUE(tree);
vector<double> point1 = {1.0, 2.0};
vector<double> point2 = {3.0, 4.0};

tree->insert(point1);
tree->insert(point2);

// No podemos verificar directamente la función inorder ya que solo imprime valores.
// Pero podemos verificar otros aspectos como el valor de la raíz después de las inserciones.
// Para un test más profundo, necesitaríamos acceso a más detalles internos o más funciones públicas.
EXPECT_EQ(tree->valori(0), 1.0);
EXPECT_FALSE(tree->empty());
}

TEST_F(KDTreeTest, TestNearestNeighbour) {
    vector<double> P1 = {0.5, 0.2};
    vector<double> P2 = {0.6, 0.1};
    vector<double> P3 = {0.2, 0.3};
    vector<double> P4 = {0.6, 0.5};
    vector<double> queryPoint = {0.3, 0.4};

    tree->insert(P1);
    tree->insert(P3);
    tree->insert(P2);
    tree->insert(P4);


// Call the nearestNeighbor function
    Node *nearest = tree->findNearestNeighbor(queryPoint);

// Verify the result
    ASSERT_TRUE(nearest != nullptr);
    EXPECT_EQ(nearest->x[0], 0.2);
    EXPECT_EQ(nearest->x[1], 0.3);
}

TEST_F(KDTreeTest, TestNearestNeighbour2) {
    vector<double> P1 = {0.5, 0.2};
    vector<double> P2 = {0.6, 0.1};
    vector<double> P3 = {0.8, 0.3};
    vector<double> P4 = {0.6, 0.5};
    vector<double> queryPoint = {0.3, 0.4};

    tree->insert(P1);
    tree->insert(P3);
    tree->insert(P2);
    tree->insert(P4);


// Call the nearestNeighbor function
    Node *nearest = tree->findNearestNeighbor(queryPoint);

// Verify the result
    ASSERT_TRUE(nearest != nullptr);
    EXPECT_EQ(nearest->x[0], 0.5);
    EXPECT_EQ(nearest->x[1], 0.2);
}

// Puedes agregar más pruebas según lo necesites.

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}