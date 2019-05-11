
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    int vacio;

}eEmployee;

typedef struct
{
    int id;
    char descripcion[20];

}eSector;

/** \brief Inicializa el empleado
 *
 * \param
 * \param
 * \return
 *
 */

void initEmployee(eEmployee vec[],int tam);

/** \brief Agrega un empleado
 *
 * \param
 * \param
 * \return
 *
 */
void addEmployee(eEmployee vec[],int tam);

/** \brief Encuentra a un empleado
 *
 * \param por medio del Id indicado
 * \param
 * \return
 *
 */
int findEmployeeById(eEmployee vec[],int tam, int id);

/** \brief Elimina a un empleado
 *
 * \param segun el Id indicado
 * \param
 * \return
 *
 */
void removeEmployee(eEmployee vec[],int tam);

/** \brief Muestra a un empleado
 *
 * \param
 * \param
 * \return
 *
 */
void printEmployee(eEmployee emp);

/** \brief Muestra a todos los empleados
 *
 * \param
 * \param
 * \return
 *
 */
void printEmployees(eEmployee vec[], int tam);

/** \brief Busca un espacio
 *
 * \param
 * \param
 * \return
 *
 */
int buscarLibre(eEmployee vec[],int tam);

/** \brief Modifica a un empleado
 *
 * \param en especifico, segun el Id indicado
 * \param
 * \return
 *
 */
void modificarEmpleado(eEmployee vec[],int tam);

/** \brief Menu de opciones
 *
 * \param
 * \param
 * \return
 *
 */
int menu();
