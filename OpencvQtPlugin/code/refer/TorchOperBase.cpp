#include "TorchOperBase.h"

#include <torch/torch.h>

 /******************
  * Class Hierarchy   类 等级制度
  * 命名空间 at::
  *     
  * 命名空间 c10::
  * 命名空间 torch::
  * struct raw
  * Union TriviallyCopyablePayload
  *
  *******************/

#include <ATen/ATen.h>
void TorchOperBase::testATen()
{
    at::Tensor a = at::ones({2, 2}, at::kInt);
    at::Tensor b = at::randn({2, 2});
    auto c = a + b.to(at::kInt);
}

#include <torch/csrc/autograd/variable.h>
#include <torch/csrc/autograd/function.h>
void TorchOperBase::AutogradTest()
{
    torch::Tensor a = torch::ones({2, 2}, torch::requires_grad());
    torch::Tensor b = torch::randn({2, 2});
    auto c = a + b;
    c.backward(); // a.grad() will now hold the gradient of c w.r.t. a.
}
