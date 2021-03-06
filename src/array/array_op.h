/*!
 *  Copyright (c) 2019 by Contributors
 * \file array/array_op.h
 * \brief Array operator templates
 */
#ifndef DGL_ARRAY_ARRAY_OP_H_
#define DGL_ARRAY_ARRAY_OP_H_

#include <dgl/array.h>
#include <vector>
#include <tuple>
#include <utility>

namespace dgl {
namespace aten {
namespace impl {

template <DLDeviceType XPU, typename IdType>
IdArray Full(IdType val, int64_t length, DLContext ctx);

template <DLDeviceType XPU, typename IdType>
IdArray Range(IdType low, IdType high, DLContext ctx);

template <DLDeviceType XPU, typename IdType>
IdArray AsNumBits(IdArray arr, uint8_t bits);

template <DLDeviceType XPU, typename IdType, typename Op>
IdArray BinaryElewise(IdArray lhs, IdArray rhs);

template <DLDeviceType XPU, typename IdType, typename Op>
IdArray BinaryElewise(IdArray lhs, IdType rhs);

template <DLDeviceType XPU, typename IdType, typename Op>
IdArray BinaryElewise(IdType lhs, IdArray rhs);

template <DLDeviceType XPU, typename IdType>
IdArray HStack(IdArray arr1, IdArray arr2);

template <DLDeviceType XPU, typename DType, typename IdType>
NDArray IndexSelect(NDArray array, IdArray index);

template <DLDeviceType XPU, typename DType>
DType IndexSelect(NDArray array, uint64_t index);

template <DLDeviceType XPU, typename IdType>
IdArray Relabel_(const std::vector<IdArray>& arrays);

template <DLDeviceType XPU, typename DType>
std::tuple<NDArray, IdArray, IdArray> Pack(NDArray array, DType pad_value);

template <DLDeviceType XPU, typename DType, typename IdType>
std::pair<NDArray, IdArray> ConcatSlices(NDArray array, IdArray lengths);

// sparse arrays

template <DLDeviceType XPU, typename IdType>
bool CSRIsNonZero(CSRMatrix csr, int64_t row, int64_t col);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray CSRIsNonZero(CSRMatrix csr, runtime::NDArray row, runtime::NDArray col);

template <DLDeviceType XPU, typename IdType>
bool CSRHasDuplicate(CSRMatrix csr);

template <DLDeviceType XPU, typename IdType>
int64_t CSRGetRowNNZ(CSRMatrix csr, int64_t row);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray CSRGetRowNNZ(CSRMatrix csr, runtime::NDArray row);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray CSRGetRowColumnIndices(CSRMatrix csr, int64_t row);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray CSRGetRowData(CSRMatrix csr, int64_t row);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray CSRGetData(CSRMatrix csr, int64_t row, int64_t col);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray CSRGetData(CSRMatrix csr, runtime::NDArray rows, runtime::NDArray cols);

template <DLDeviceType XPU, typename IdType>
std::vector<runtime::NDArray> CSRGetDataAndIndices(
    CSRMatrix csr, runtime::NDArray rows, runtime::NDArray cols);

template <DLDeviceType XPU, typename IdType>
CSRMatrix CSRTranspose(CSRMatrix csr);

// Convert CSR to COO
template <DLDeviceType XPU, typename IdType>
COOMatrix CSRToCOO(CSRMatrix csr);

// Convert CSR to COO using data array as order
template <DLDeviceType XPU, typename IdType>
COOMatrix CSRToCOODataAsOrder(CSRMatrix csr);

template <DLDeviceType XPU, typename IdType>
CSRMatrix CSRSliceRows(CSRMatrix csr, int64_t start, int64_t end);

template <DLDeviceType XPU, typename IdType>
CSRMatrix CSRSliceRows(CSRMatrix csr, runtime::NDArray rows);

template <DLDeviceType XPU, typename IdType>
CSRMatrix CSRSliceMatrix(CSRMatrix csr, runtime::NDArray rows, runtime::NDArray cols);

template <DLDeviceType XPU, typename IdType>
void CSRSort_(CSRMatrix* csr);

// FloatType is the type of probability data.
template <DLDeviceType XPU, typename IdType, typename FloatType>
COOMatrix CSRRowWiseSampling(
    CSRMatrix mat, IdArray rows, int64_t num_samples, FloatArray prob, bool replace);

template <DLDeviceType XPU, typename IdType>
COOMatrix CSRRowWiseSamplingUniform(
    CSRMatrix mat, IdArray rows, int64_t num_samples, bool replace);

// FloatType is the type of weight data.
template <DLDeviceType XPU, typename IdType, typename FloatType>
COOMatrix CSRRowWiseTopk(
    CSRMatrix mat, IdArray rows, int64_t k, FloatArray weight, bool ascending);

///////////////////////////////////////////////////////////////////////////////////////////

template <DLDeviceType XPU, typename IdType>
bool COOIsNonZero(COOMatrix coo, int64_t row, int64_t col);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray COOIsNonZero(COOMatrix coo, runtime::NDArray row, runtime::NDArray col);

template <DLDeviceType XPU, typename IdType>
bool COOHasDuplicate(COOMatrix coo);

template <DLDeviceType XPU, typename IdType>
int64_t COOGetRowNNZ(COOMatrix coo, int64_t row);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray COOGetRowNNZ(COOMatrix coo, runtime::NDArray row);

template <DLDeviceType XPU, typename IdType>
std::pair<runtime::NDArray, runtime::NDArray>
COOGetRowDataAndIndices(COOMatrix coo, int64_t row);

template <DLDeviceType XPU, typename IdType>
runtime::NDArray COOGetData(COOMatrix coo, int64_t row, int64_t col);

template <DLDeviceType XPU, typename IdType>
std::vector<runtime::NDArray> COOGetDataAndIndices(
    COOMatrix coo, runtime::NDArray rows, runtime::NDArray cols);

template <DLDeviceType XPU, typename IdType>
COOMatrix COOTranspose(COOMatrix coo);

template <DLDeviceType XPU, typename IdType>
CSRMatrix COOToCSR(COOMatrix coo);

template <DLDeviceType XPU, typename IdType>
COOMatrix COOSliceRows(COOMatrix coo, int64_t start, int64_t end);

template <DLDeviceType XPU, typename IdType>
COOMatrix COOSliceRows(COOMatrix coo, runtime::NDArray rows);

template <DLDeviceType XPU, typename IdType>
COOMatrix COOSliceMatrix(COOMatrix coo, runtime::NDArray rows, runtime::NDArray cols);

template <DLDeviceType XPU, typename IdType>
COOMatrix COOSort(COOMatrix mat, bool sort_column);

// FloatType is the type of probability data.
template <DLDeviceType XPU, typename IdType, typename FloatType>
COOMatrix COORowWiseSampling(
    COOMatrix mat, IdArray rows, int64_t num_samples, FloatArray prob, bool replace);

template <DLDeviceType XPU, typename IdType>
COOMatrix COORowWiseSamplingUniform(
    COOMatrix mat, IdArray rows, int64_t num_samples, bool replace);

// FloatType is the type of weight data.
template <DLDeviceType XPU, typename IdType, typename FloatType>
COOMatrix COORowWiseTopk(
    COOMatrix mat, IdArray rows, int64_t k, FloatArray weight, bool ascending);

}  // namespace impl
}  // namespace aten
}  // namespace dgl

#endif  // DGL_ARRAY_ARRAY_OP_H_
